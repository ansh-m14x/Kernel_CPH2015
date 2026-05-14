# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.# Custom Kernel Refactor Project

This repository contains specialized kernel modifications designed to streamline system overhead and improve storage responsiveness by replacing aggressive performance locks with efficient, logic-based optimizations.

## 🛠 Core Modifications

### 1. SCSI Logging & Buffer Management
The legacy SCSI logging mechanism has been refactored to reduce memory footprint and prevent potential deadlocks in atomic contexts.
*   **Refactored Logic**: Removed the complex `scsi_log_buf` structure and per-CPU bitmask management.
*   **Implementation**: `scsi_log_reserve_buffer` now utilizes a direct `kmalloc` with a fixed **128-byte** length and the `GFP_ATOMIC` flag.
*   **Cleanup**: Removed the redundant `#define SCSI_LOG_BUFSIZE 128` from `include/scsi/scsi_dbg.h` to rely on localized allocation.

### 2. Block Layer & I/O Scheduling (CFQ)
Optimizations were applied to the Completely Fair Queuing (CFQ) scheduler to enhance multitasking and random-access performance.
*   **`cfq_quantum`**: Increased from **8 to 16** to allow a higher number of simultaneous requests to the storage controller.
*   **`cfq_back_seek_penalty`**: Reduced from **2 to 1** to improve responsiveness during random-access patterns.
*   **I/O Accounting Override**: To reduce CPU overhead, filesystem-level request accounting (`REQ_TYPE_FS`) has been disabled by forcing the check to return `false`.

### 3. Optimized Integer Square Root (`int_sqrt.c`)
The `int_sqrt` function was updated with a bit-skipping optimization to improve mathematical throughput.
*   **Fast-Forward Logic**: Added a loop to skip bits larger than the input value before starting the main calculation.
*   **Efficiency**: Significantly reduces iteration counts for smaller inputs while maintaining `floor(sqrt(x))` accuracy.
*   **Stability**: Removed the `inline` keyword to ensure proper symbol exportation via `EXPORT_SYMBOL`.

## 🔍 Verification & Path Discovery
The following paths have been verified on the target device (See: f5505f01-c320-41ea-95a6-de93b1741bb5 and de9b6390-afbf-4043-b848-8cab86d85d13):

### SCSI Logging Level
Confirm the presence of the logging level control file:
- **Path**: `/proc/sys/dev/scsi/logging_level`

### I/O Scheduler Tunables (eMMC)
Confirm active parameters on the primary storage node:
```bash
su -c "grep . /sys/block/mmcblk0/queue/iosched/quantum /sys/block/mmcblk0/queue/iosched/back_seek_penalty"


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
