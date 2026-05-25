#include "matmul.h"

void matmul_tiled(data_t A[N][N], data_t B[N][N], data_t C[N][N]) {
#pragma HLS INTERFACE ap_memory port=A
#pragma HLS INTERFACE ap_memory port=B
#pragma HLS INTERFACE ap_memory port=C
#pragma HLS INTERFACE ap_ctrl_hs port=return

    // Local tile buffers — these will map to BRAM
    data_t A_local[TILE][TILE];
    data_t B_local[TILE][TILE];

    // Partition to allow multiple reads per cycle
    #pragma HLS ARRAY_PARTITION variable=A_local complete dim=2
    #pragma HLS ARRAY_PARTITION variable=B_local complete dim=1

    // Initialize output matrix
    INIT_ROW: for (int i = 0; i < N; i++) {
        INIT_COL: for (int j = 0; j < N; j++) {
            C[i][j] = 0;
        }
    }

    // Tiled matrix multiplication
    TILE_ROW: for (int ii = 0; ii < N; ii += TILE) {
        TILE_COL: for (int jj = 0; jj < N; jj += TILE) {
            TILE_ACC: for (int kk = 0; kk < N; kk += TILE) {

                // Load tile of A into local buffer
                LOAD_A_ROW: for (int i = 0; i < TILE; i++) {
                    LOAD_A_COL: for (int k = 0; k < TILE; k++) {
                        A_local[i][k] = A[ii + i][kk + k];
                    }
                }

                // Load tile of B into local buffer
                LOAD_B_ROW: for (int k = 0; k < TILE; k++) {
                    LOAD_B_COL: for (int j = 0; j < TILE; j++) {
                        B_local[k][j] = B[kk + k][jj + j];
                    }
                }

                // Compute on local tiles
                COMP_ROW: for (int i = 0; i < TILE; i++) {
                    COMP_COL: for (int j = 0; j < TILE; j++) {
                        data_t sum = 0;
                        COMP_ACC: for (int k = 0; k < TILE; k++) {
                            sum += A_local[i][k] * B_local[k][j];
                        }
                        C[ii + i][jj + j] += sum;
                    }
                }
            }
        }
    }
}
