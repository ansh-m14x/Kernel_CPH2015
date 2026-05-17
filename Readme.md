# King Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized, custom kernel source for the Oppo A31 (Project: `oppo6765_19581`). It is designed to minimize system overhead, maximize storage throughput, and eliminate aggressive stock performance locks.

## 🛠 Core Project Upgrades

### 1. Core Upstream Base Bump
* **Version Update**: Upstreamed the base kernel from Linux version `4.9.117` directly to `4.9.119`.
* **Impact**: Integrates essential security patches, upstream bug fixes, and critical stability improvements for the overall framework layer.

### 2. Native F2FS Integration
* **Filesystem Engine**: Implemented full, high-performance **F2FS (Flash-Friendly File System)** drivers.
* **Optimization**: Specifically structured to accelerate user partition read/write capabilities, optimize gaming block execution, and reduce application initialization latency. 
* *Note for Developers: Ensure your vendor/recovery fstab structures utilize proper multi-line layout mappings to handle dynamic block mounting safely.*

### 3. SCSI Logging & Buffer Management Refactor
* **Refactored Logic**: Removed the complex `scsi_log_buf` structure and per-CPU bitmask management.
* **Implementation**: `scsi_log_reserve_buffer` now utilizes a direct `kmalloc` with a fixed **128-byte** length and the `GFP_ATOMIC` flag to prevent potential deadlocks in atomic contexts.
* **Cleanup**: Removed the redundant `#define SCSI_LOG_BUFSIZE 128` from `include/scsi/scsi_dbg.h` to rely entirely on localized allocation.

### 4. Block Layer & I/O Scheduling (CFQ Tuning)
Optimizations were applied to the Completely Fair Queuing (CFQ) scheduler to enhance multitasking and random-access performance on eMMC hardware:
* **`cfq_quantum`**: Increased from **8 to 16** to allow a higher number of simultaneous requests to the storage controller.
* **`cfq_back_seek_penalty`**: Reduced from **2 to 1** to drastically improve responsiveness during random-access patterns.
* **I/O Accounting Override**: Bypassed filesystem-level request accounting (`REQ_TYPE_FS`) by forcing the check to return `false`, freeing up valuable CPU cycles.

### 5. Optimized Integer Square Root (`int_sqrt.c`)
* **Fast-Forward Logic**: Added a specialized bit-skipping loop to skip bits larger than the input value before starting the main calculation loop.
* **Efficiency**: Significantly reduces total iteration counts for smaller inputs while maintaining absolute `floor(sqrt(x))` accuracy.
* **Stability**: Removed the `inline` keyword to ensure proper symbol exportation via `EXPORT_SYMBOL`.

### 6. Task Scheduler Real-Time Boost
* **RT Throttling Removal**: To ensure unrestricted performance allocation for high-priority system tasks and heavy mobile gaming, the Real-Time (RT) throttling logic has been completely stripped out of the scheduler.

---

## 🔍 Verification & Path Discovery

### SCSI Logging Level Control
Confirm the presence of the active logging level control file node:
* **Path**: `/proc/sys/dev/scsi/logging_level`

### I/O Scheduler Tunables (eMMC)
Confirm active parameters on the primary storage node via an elevated terminal emulator or ADB shell:
```bash
su -c "grep . /sys/block/mmcblk0/queue/iosched/quantum /sys/block/mmcblk0/queue/iosched/back_seek_penalty"
