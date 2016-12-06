cmake_minimum_required(VERSION 3.7)

project(noah VERSION 0.3.9)

configure_file(bin/noah.in ${PROJECT_SOURCE_DIR}/bin/noah @ONLY)
configure_file(include/version.h.in ${PROJECT_SOURCE_DIR}/include/version.h)

set(CMAKE_C_FLAGS "-g -Wall -Wextra -Wno-unused-parameter -std=gnu11")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
include_directories(include)

add_executable(noah
  lib/vmm.c
  src/main.c
  src/meta_strace.c
  src/base.c
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
  src/proc/ptrace.c
  )
target_link_libraries(noah pthread "-framework Hypervisor")

install(PROGRAMS bin/noah DESTINATION bin)
install(TARGETS noah DESTINATION libexec)

enable_testing()
add_subdirectory(test)
