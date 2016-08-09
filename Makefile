CFLAGS += -g
LDFLAGS += -framework Hypervisor

TEST_UPROGS := $(addprefix test/test_assertion/build/, fib)\
               $(addprefix test/test_stdout/build/, hello cat echo)

all: build/noah $(TEST_UPROGS)

dev: CFLAGS += -DDEBUG_MODE=1
dev: build/noah

build/noah: src/main.o src/debug.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test/test_assertion/build/%: test/test_assertion/%.c test/include/*.h test/include/noah.S
	$(MAKE_TEST_UPROGS)
test/test_stdout/build/%: test/test_stdout/%.c test/include/*.h test/include/noah.S
	$(MAKE_TEST_UPROGS)

MAKE_TEST_UPROGS = rsync $^ idylls.jp:/tmp/$(USER)/;\
                   ssh idylls.jp "gcc -nostdlib -static /tmp/$(USER)/$*.c /tmp/$(USER)/noah.S -o /tmp/$(USER)/$*";\
                   rsync idylls.jp:/tmp/$(USER)/$* $@

run: build/noah test/test_stdout/build/hello
	./build/noah test/test_stdout/build/hello
clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah
	$(RM) test/test_assertion/build/* test/test_stdout/build/*

test: build/noah $(TEST_UPROGS)
	./test/test.rb

.PHONY: all run test clean
