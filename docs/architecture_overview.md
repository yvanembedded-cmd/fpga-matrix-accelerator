# FPGA Matrix Accelerator Architecture Overview

## Objective

This project implements a high-performance FPGA-based matrix multiplication accelerator using Xilinx Vitis HLS targeting the Zynq-7020 SoC platform.

The architecture explores progressive optimization strategies for improving:
- Throughput
- Latency
- Parallelism
- Memory efficiency

while analyzing FPGA resource utilization tradeoffs.

---

## Accelerator Pipeline

The accelerator processes matrix multiplication through the following stages:

1. Input matrices are loaded from external memory
2. Matrix tiles are transferred into local FPGA buffers
3. Multiply-Accumulate (MAC) operations are performed
4. Partial sums are accumulated
5. Results are written back to output memory

---

## Architectural Variants

### Baseline Architecture
Implements standard triple nested loop matrix multiplication with sequential execution.

### Tiled Architecture
Introduces local tile buffering to improve memory locality and reduce repeated external memory accesses.

### Pipelined Architecture
Applies loop pipelining to achieve Initiation Interval (II=1) scheduling for improved throughput.

### Unrolled Architecture
Replicates MAC units to maximize parallel execution and exploit FPGA DSP resources.

---

## FPGA Platform

- FPGA Device: Xilinx Zynq-7020
- Board: PYNQ-Z2
- Toolchain:
  - Vitis HLS 2023.2
  - Vivado 2023.2
- Clock Frequency: 100 MHz

---

## Key Design Goals

- Maximize parallelism
- Improve data reuse
- Reduce computation latency
- Explore HLS optimization directives
- Analyze FPGA resource-performance tradeoffs
