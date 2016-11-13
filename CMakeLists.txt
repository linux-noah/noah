cmake_minimum_required(VERSION 3.7)

project(noah)

set(CMAKE_C_FLAGS "-std=gnu11")

include_directories(include)

add_executable(noah
  lib/vmm.c
  src/main.c
  src/meta_strace.c
  src/common.c
  src/conv.c
  src/debug.c
  src/proc/exec.c
  src/proc/fork.c
  src/proc/process.c
  src/net/net.c
  src/ipc/futex.c
  src/ipc/signal.c
  src/fs/fs.c
  src/sys/sys.c
  src/sys/time.c
  src/mm/mm.c
  src/mm/mmap.c
  src/mm/malloc.c
  )

target_link_libraries(noah pthread "-framework Hypervisor")
