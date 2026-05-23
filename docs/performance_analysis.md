# Performance Analysis

## Experimental Configurations

The accelerator was evaluated across multiple matrix and tile sizes.

Configurations:
- N=4, T=2
- N=32, T=16
- N=32, T=32

---

## Throughput Results

| Design Variant | Throughput |
|---|---|
| Baseline | 399 MFLOP/s |
| Tiled | 1244 MFLOP/s |
| Unrolled | 3176 MFLOP/s |

---

## Resource Utilization Trends

Increasing parallelism improves throughput but increases:
- LUT usage
- Flip-flop usage
- DSP consumption

The fully unrolled architecture consumed:
- 12,686 LUTs
- 75,126 FFs
- 96 DSPs

---

## Architectural Insights

Key observations:
1. Tiling improves memory locality
2. Pipelining improves throughput
3. Unrolling provides the largest acceleration
4. BRAM usage depends on tile size

---

## Final Result

The optimized N=32, T=32 configuration achieved:
- Nearly 3.2 GFLOP/s throughput
- 7.96× speedup over baseline

on the Xilinx Zynq-7020 FPGA platform.
