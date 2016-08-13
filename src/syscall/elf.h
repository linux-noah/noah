#include "../common.h"

struct elf_header {
  uint magic;
  uchar cpubit;
  uchar endian;
  uchar version;
  uchar abi;
  ulong unused;
  ushort type;
  ushort isa;
  uint version2;
  ulong entry;
  ulong phoff;
  ulong shoff;
  uint flags;
  ushort ehsize;
  ushort phentsize;
  ushort phnum;
  ushort shentsize;
  ushort shnum;
  ushort shstrndx;
};

#define ELF_TYPE_EXEC 2

#define ELF_ISA_X64 62

#define ELF_PROG_LOAD 1

struct program_header {
  uint type;
  uint flags;
  ulong offset;
  ulong vaddr;
  ulong paddr;
  ulong filesz;
  ulong memsz;
  ulong align;
};

#define PT_NULL        0
#define PT_LOAD        1

struct section_header {
  uint name;
  uint type;
  ulong flags;
  ulong addr;
  ulong offset;
  ulong size;
  uint link;
  uint info;
  ulong align;
  ulong entsize;
};

