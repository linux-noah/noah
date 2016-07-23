ASFLAGS += -m32
CFLAGS += -g
LDFLAGS += -framework Hypervisor

all: build/noah

dev: CFLAGS += -DDEBUG_MODE=1
dev: build/noah

build/noah: src/main.o src/debug.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

hello: user/hello.c
	echo RUN ME ON LINUX
	gcc -nostdlib -static user/hello.c -o hello
fib: user/fib.c
	echo RUN ME ON LINUX
	gcc -nostdlib -static user/fib.c -o fib

run: build/noah
	./build/noah hello

clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah

.PHONY: all run clean
