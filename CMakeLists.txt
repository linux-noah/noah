cmake_minimum_required(VERSION 3.7)

project(noah C)

set(CMAKE_C_FLAGS "-g -std=gnu11")
set(CMAKE_C_FLAGS_DEBUG "-DDEBUG_MODE=1 -O0")
set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_BUILD_TYPE Release)
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

install(FILES bin/noah DESTINATION bin)
install(TARGETS noah DESTINATION libexec)
