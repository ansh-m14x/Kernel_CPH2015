# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.

## 🛠️ Kernel Build Specs: Extreme Performance
**Architecture:** ARM64 (aarch64-linux-gnu-)
**Device:** Oppo A31 (MT6765 - oppo6765_19581)
# Custom Kernel Refactor - SCSI & I/O Optimization

This branch contains a refactored approach to kernel logging and I/O scheduling, moving away from aggressive performance locks toward a more streamlined, stable codebase.

## 🛠 Changes Overview

### SCSI Logging Simplified
We have replaced the legacy per-CPU spooling mechanism for SCSI logging.
- **Old Method**: Used a complex bitmask and pre-allocated CPU buffers.
- **New Method**: Implements atomic dynamic allocation. This reduces the memory footprint and simplifies the logic in `drivers/scsi/scsi_logging.c`.

### I/O Scheduler Tunings (CFQ)
Optimized the Completely Fair Queuing (CFQ) scheduler for better multitasking:
- **cfq_quantum**: Doubled to 16.
- **cfq_back_penalty**: Reduced to 1 to improve performance on fragmented storage.

### Block Layer Overrides
To reduce unnecessary CPU cycles during high I/O loads, filesystem-level request accounting (`REQ_TYPE_FS`) has been disabled by forcing the I/O stat check to return `false`.

## 📂 File References
- **`include/scsi/scsi_dbg.h`**: Removed hardcoded buffer definitions (See: 1778734896211.jpeg).
- **`drivers/scsi/scsi_logging.c`**: Implementation of kmalloc-based buffer management (See: 1778734882145.jpeg).
- **`block/cfq-iosched.c`**: Adjusted scheduling tunables (See: 1778734818482.jpeg).

## 🚀 How to Build
1. Sync sources.
2. Apply the provided commits.
3. Use your standard `defconfig` and compile via your preferred toolchain (e.g., Clang/GCC via Termux or Crave).




## 🛠 Build Information
*   **Device**: Oppo A31 (CPH2015 / CPH2073 / CPH2081)
*   **Architecture**: ARM64
*   **Cross-Compiler**: `aarch64-linux-gnu-`
*   **Target Project**: `oppo6765_19581`
*   **Display Resolution**: 720x1600 (HD+)

## ⚠️ Disclaimer
This kernel is intended for technical users and custom ROM developers. Modification of kernel parameters can lead to system instability if not handled correctly. Always ensure you have a backup of your stock `boot.img` before flashing.
