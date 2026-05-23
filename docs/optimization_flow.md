# Optimization Flow

## Progressive Optimization Strategy

The accelerator was optimized incrementally to isolate the contribution of each architectural enhancement.

---

## Stage 1 — Baseline Design

The baseline implementation performs matrix multiplication using a standard triple nested loop structure.

Characteristics:
- Sequential execution
- Minimal FPGA resource utilization
- Low throughput
- Simple implementation

---

## Stage 2 — Tiled Architecture

Loop tiling partitions matrices into smaller sub-blocks stored in local FPGA buffers.

Benefits:
- Improved memory locality
- Reduced external memory accesses
- Better data reuse

Tradeoff:
- Increased BRAM and control overhead

---

## Stage 3 — Loop Pipelining

Loop pipelining enables overlapping operations across clock cycles.

Applied using:
```cpp
#pragma HLS PIPELINE II=1
```

Benefits:
- Increased throughput
- Reduced idle cycles
- Improved execution efficiency

---

## Stage 4 — Loop Unrolling

Loop unrolling replicates multiply-accumulate hardware for parallel execution.

Applied using:
```cpp
#pragma HLS UNROLL
```

Benefits:
- Massive throughput increase
- Parallel MAC execution
- DSP utilization maximization

Tradeoff:
- Significant LUT and FF growth

---

## Final Optimized Architecture

The final optimized configuration:
- Matrix Size: N = 32
- Tile Size: T = 32

achieved:
- Nearly 3.2 GFLOP/s throughput
- 7.96× speedup over baseline
