# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.

​🛠 Core Modifications
​1. SCSI Logging & Buffer Management
​The legacy SCSI logging mechanism has been refactored to reduce memory footprint and prevent potential deadlocks in atomic contexts.
​Refactored Logic: Removed the complex scsi_log_buf structure and per-CPU bitmask management.
​Implementation: scsi_log_reserve_buffer now utilizes a direct kmalloc with a fixed 128-byte length and the GFP_ATOMIC flag.
​Cleanup: Removed the redundant #define SCSI_LOG_BUFSIZE 128 from include/scsi/scsi_dbg.h to rely on localized allocation.
​2. Block Layer & I/O Scheduling (CFQ)
​Optimizations were applied to the Completely Fair Queuing (CFQ) scheduler to enhance multitasking and random-access performance.
​cfq_quantum: Increased from 8 to 16 to allow a higher number of simultaneous requests to the storage controller.
​cfq_back_penalty: Reduced from 2 to 1 to improve responsiveness during seek-heavy operations.
​I/O Accounting Override: To reduce CPU overhead, filesystem-level request accounting (REQ_TYPE_FS) has been disabled by forcing the check to return false.
​3. Optimized Integer Square Root (int_sqrt.c)
​The int_sqrt function was updated with a bit-skipping optimization to improve mathematical throughput.
​Fast-Forward Logic: Added a loop to skip bits larger than the input value before starting the main calculation.
​Efficiency: Significantly reduces iteration counts for smaller inputs while maintaining floor(sqrt(x)) accuracy.
​Stability: Removed the inline keyword to ensure proper symbol exportation via EXPORT_SYMBOL.
​📂 Key Files
​drivers/scsi/scsi_logging.c: Implementation of simplified buffer management.
​include/scsi/scsi_dbg.h: Cleaned up SCSI constants and headers.
​block/cfq-iosched.c: Updated I/O scheduler tunables.
​lib/int_sqrt.c: Optimized mathematical logic.

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
