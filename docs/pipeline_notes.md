# Pipeline Behavior

## Loop Pipelining

Loop pipelining allows multiple operations to overlap across clock cycles.

This optimization was applied using:

```cpp
#pragma HLS PIPELINE II=1
```

---

## Initiation Interval (II)

II=1 means:
- a new operation begins every clock cycle

This maximizes hardware utilization and improves throughput.

---

## Pipeline Advantages

Benefits include:
- Improved throughput
- Reduced idle cycles
- Better compute efficiency
- Continuous hardware utilization

---

## Pipeline Limitation

For small matrix sizes:
- pipeline startup overhead dominates execution time

For larger matrices:
- steady-state execution provides significant performance gains

---

## Performance Impact

Pipeline optimization contributed to:
- lower effective latency
- improved throughput
- higher accelerator utilization

especially for:
- N = 32
- T = 16
- T = 32
