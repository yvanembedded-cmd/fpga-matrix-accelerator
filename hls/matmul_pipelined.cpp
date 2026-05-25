#include "matmul.h"

void matmul_pipelined(data_t A[N][N], data_t B[N][N], data_t C[N][N]) {
#pragma HLS INTERFACE ap_memory port=A
#pragma HLS INTERFACE ap_memory port=B
#pragma HLS INTERFACE ap_memory port=C
#pragma HLS INTERFACE ap_ctrl_hs port=return

    data_t A_local[TILE][TILE];
    data_t B_local[TILE][TILE];

    #pragma HLS ARRAY_PARTITION variable=A_local complete dim=2
    #pragma HLS ARRAY_PARTITION variable=B_local complete dim=1

    // Initialize output matrix
    INIT_ROW: for (int i = 0; i < N; i++) {
        INIT_COL: for (int j = 0; j < N; j++) {
            #pragma HLS PIPELINE II=1
            C[i][j] = 0;
        }
    }

    // Tiled matrix multiplication with pipelined loops
    TILE_ROW: for (int ii = 0; ii < N; ii += TILE) {
        TILE_COL: for (int jj = 0; jj < N; jj += TILE) {
            TILE_ACC: for (int kk = 0; kk < N; kk += TILE) {

                // Load tile of A — pipelined
                LOAD_A: for (int i = 0; i < TILE; i++) {
                    for (int k = 0; k < TILE; k++) {
                        #pragma HLS PIPELINE II=1
                        A_local[i][k] = A[ii + i][kk + k];
                    }
                }

                // Load tile of B — pipelined
                LOAD_B: for (int k = 0; k < TILE; k++) {
                    for (int j = 0; j < TILE; j++) {
                        #pragma HLS PIPELINE II=1
                        B_local[k][j] = B[kk + k][jj + j];
                    }
                }

                // Compute — pipelined
                COMPUTE: for (int i = 0; i < TILE; i++) {
                    for (int j = 0; j < TILE; j++) {
                        #pragma HLS PIPELINE II=1
                        data_t sum = 0;
                        for (int k = 0; k < TILE; k++) {
                            sum += A_local[i][k] * B_local[k][j];
                        }
                        C[ii + i][jj + j] += sum;
                    }
                }
            }
        }
    }
}
