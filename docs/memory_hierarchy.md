# Memory Hierarchy and Dataflow

## Overview

Efficient memory usage is critical for FPGA accelerator performance.

This design improves performance by introducing tiled local buffering to maximize data reuse and reduce repeated external memory accesses.

---

## Global Memory

Input matrices:
- Matrix A
- Matrix B

are initially stored in external memory.

Directly accessing external memory during every multiply operation creates a memory bottleneck.

---

## Local Tile Buffers

To reduce memory traffic, sub-blocks of matrices are copied into local FPGA buffers:

```cpp
data_t A_local[TILE][TILE];
data_t B_local[TILE][TILE];
```

These buffers allow:
- Faster on-chip access
- Data reuse
- Reduced memory latency

---

## Array Partitioning

Array partitioning was applied to improve parallel access:

```cpp
#pragma HLS ARRAY_PARTITION variable=A_local complete dim=2
#pragma HLS ARRAY_PARTITION variable=B_local complete dim=1
```

Benefits:
- Multiple reads per cycle
- Improved DSP utilization
- Higher throughput

---

## BRAM Utilization

For small tile sizes:
- Buffers are implemented using registers

For larger tile sizes:
- Buffers are mapped into BRAM blocks

The T=32 design utilized:
- 64 BRAM blocks

This improved timing performance while reducing register pressure.
