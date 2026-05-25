# FPGA-Based Matrix Multiplication Accelerator

High-performance FPGA matrix multiplication accelerator implemented using Xilinx Vitis HLS on the Xilinx Zynq-7020 SoC (PYNQ-Z2 platform).

This project explores architectural optimization techniques for FPGA acceleration including:
- Loop Tiling
- Loop Pipelining
- Loop Unrolling
- Array Partitioning

The goal is to improve throughput, reduce latency, and analyze FPGA resource tradeoffs for matrix multiplication workloads commonly used in machine learning and scientific computing.

---

## Hardware Platform

- FPGA: Xilinx Zynq-7020
- Development Board: PYNQ-Z2
- Toolchain:
  - Vitis HLS 2023.2
  - Vivado 2023.2
- Target Clock Frequency: 100 MHz

---

## Project Features

- Baseline matrix multiplication implementation
- Tiled architecture for memory locality optimization
- Pipelined compute loops with II=1 scheduling
- Fully unrolled MAC operations for parallel execution
- FPGA resource utilization analysis
- Throughput and latency benchmarking
- Functional verification using C simulation and RTL co-simulation

---

## Optimization Flow

### 1. Baseline Design
Sequential triple nested loop matrix multiplication implementation.

### 2. Tiled Architecture
Introduces on-chip local buffering to improve memory reuse and reduce off-chip accesses.

### 3. Pipelined Design
Applies loop pipelining directives to achieve improved throughput.

### 4. Unrolled Design
Replicates multiply-accumulate hardware to maximize parallelism.

---

## Experimental Results

| Design Variant | Throughput |
|---|---|
| Baseline | 399 MFLOP/s  |
| Tiled    | 1244 MFLOP/s |
| Unrolled | 3176 MFLOP/s |

Achieved nearly 3.2 GFLOP/s on the Zynq-7020 FPGA platform.

---

## Repository Structure

```bash
fpga-matrix-accelerator/
│
├── docs/
├── hls/
├── testbench/
├── waveforms/
└── reports/
```

## Documentation

Detailed architecture documentation is available in the `/docs` directory:

- Architecture Overview
- Optimization Flow
- Memory Hierarchy
- Pipeline Behavior
- Performance Analysis

## Running the Project

1. Open Vitis HLS 2023.2
2. Create a new project
3. Add source files from `/hls`
4. Add testbench from `/testbench`
5. Run:
   - C Simulation
   - C Synthesis
   - C/RTL Co-Simulation

---

## Future Improvements

- Systolic array architecture
- CNN acceleration support
- Floating-point arithmetic
- AXI-stream integration
- Larger matrix dimensions
- Transformer/GEMM acceleration

---

## Author

Yvan Brillant Bota  
ECE @ KSU  
Embedded Systems | FPGA | Energy Systems | Hardware Acceleration
