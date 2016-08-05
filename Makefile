CFLAGS += -g
LDFLAGS += -framework Hypervisor

USERS := _cat _fib _hello

all: build/noah $(USERS)

dev: CFLAGS += -DDEBUG_MODE=1
dev: build/noah

build/noah: src/main.o src/debug.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

_%: user/%.c user/noah.h
	rsync $^ user/noah.h idylls.jp:/tmp/$(USER)
	ssh idylls.jp "gcc -nostdlib -static /tmp/$(USER)/$*.c -o /tmp/$(USER)/$@"
	rsync idylls.jp:/tmp/$(USER)/$@ ./$@

run: build/noah _hello
	./build/noah _hello

clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah
	$(RM) _*

.PHONY: all run clean
