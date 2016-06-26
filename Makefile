ASFLAGS += -m32
CFLAGS += -g
LDFLAGS += -framework Hypervisor

all: build/noah

dev: CFLAGS += -DDEBUG_MODE=1
dev: build/noah

build/noah: src/main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

hello: src/hello.S
	echo RUN ME ON LINUX
	as --32 src/hello.S
	ld -m elf_i386 -o hello a.out

run: build/noah
	./build/noah hello

clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah

.PHONY: all run clean
