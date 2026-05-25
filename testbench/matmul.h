#ifndef MATMUL_H
#define MATMUL_H

#include <ap_int.h>

// Matrix dimension — start with 4 for fast simulation
//#define N 4

// Tile size for optimized variants (must evenly divide N)
//#define TILE 2

#define N 32       // was 4
#define TILE 32     // was 2 — must evenly divide N (32/8 = 4 ✅)


// Data type
typedef int data_t;

// Function prototypes
void matmul_baseline(data_t A[N][N], data_t B[N][N], data_t C[N][N]);
void matmul_tiled(data_t A[N][N], data_t B[N][N], data_t C[N][N]);
void matmul_pipelined(data_t A[N][N], data_t B[N][N], data_t C[N][N]);
void matmul_unrolled(data_t A[N][N], data_t B[N][N], data_t C[N][N]);

#endif
