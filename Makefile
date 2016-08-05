CFLAGS += -g
LDFLAGS += -framework Hypervisor

USERS := $(patsubst test/%.c, test/build/%, $(wildcard test/*.c))

all: build/noah $(USERS)

dev: CFLAGS += -DDEBUG_MODE=1
dev: build/noah

build/noah: src/main.o src/debug.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test/build/%: test/%.c
	rsync $^ test/noah.h idylls.jp:/tmp/$(USER)/
	ssh idylls.jp "gcc -nostdlib -static /tmp/$(USER)/$*.c -o /tmp/$(USER)/$*"
	rsync idylls.jp:/tmp/$(USER)/$* $@

run: build/noah _hello
	./build/noah _hello
clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah
	$(RM) test/build/*

test: $(USERS)
	./test/test.rb


.PHONY: all run test clean
