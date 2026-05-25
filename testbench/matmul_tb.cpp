#include <iostream>
#include <cstdlib>
#include "matmul.h"

int main() {
    data_t A[N][N], B[N][N];
    data_t C_hw[N][N], C_ref[N][N];

    // Initialize matrices with small random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Golden reference — software matrix multiply
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            data_t sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C_ref[i][j] = sum;
        }
    }

    // ============================================
    //  SWAP THIS CALL FOR EACH DESIGN VARIANT
    //  Uncomment the one you are testing,
    //  comment out the rest.
    // ============================================

    //matmul_baseline(A, B, C_hw);
     matmul_tiled(A, B, C_hw);
     //  matmul_pipelined(A, B, C_hw);
    // matmul_unrolled(A, B, C_hw);

    // Verify hardware output against golden reference
    int mismatches = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (C_hw[i][j] != C_ref[i][j]) {
                std::cout << "MISMATCH at [" << i << "][" << j << "]: "
                          << "expected " << C_ref[i][j]
                          << ", got " << C_hw[i][j] << std::endl;
                mismatches++;
            }
        }
    }

    if (mismatches == 0) {
        std::cout << "============================================" << std::endl;
        std::cout << "          *** TEST PASSED ***" << std::endl;
        std::cout << "============================================" << std::endl;
    } else {
        std::cout << "============================================" << std::endl;
        std::cout << "  *** TEST FAILED: " << mismatches
                  << " mismatches ***" << std::endl;
        std::cout << "============================================" << std::endl;
    }

    // Return 0 = pass for Vitis HLS
    return mismatches;
}
