#include "matmul.h"

void matmul_baseline(data_t A[N][N], data_t B[N][N], data_t C[N][N]) {
#pragma HLS INTERFACE ap_memory port=A
#pragma HLS INTERFACE ap_memory port=B
#pragma HLS INTERFACE ap_memory port=C
#pragma HLS INTERFACE ap_ctrl_hs port=return

    ROW: for (int i = 0; i < N; i++) {
        COL: for (int j = 0; j < N; j++) {
            data_t sum = 0;
            ACC: for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}
