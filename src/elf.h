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
  uint entry;
  uint phoff;
  uint shoff;
  uint flags;
  ushort ehsize;
  ushort phentsize;
  ushort phnum;
  ushort shentsize;
  ushort shnum;
  ushort shstrndx;
};

#define ELF_PROG_LOAD 1

struct program_header {
  uint type;
  uint offset;
  uint vaddr;
  uint paddr;
  uint filesz;
  uint memsz;
  uint flags;
  uint align;
};

struct section_header {
  uint name;
  uint type;
  uint flags;
  uint addr;
  uint offset;
  uint size;
  uint link;
  uint info;
  uint align;
  uint entsize;
};
