CFLAGS += -g -Iinclude -std=gnu11
LDFLAGS += -framework Hypervisor -lpthread

SRCS := \
	src/main.c\
	src/vmm.c\
	src/meta_strace.c\
	src/debug.c\
	src/syscall/common.c\
	src/syscall/fs.c\
	src/syscall/exec.c\
	src/syscall/fork.c\
	src/syscall/process.c\
	src/syscall/mm.c\
	src/syscall/signal.c\
	src/syscall/time.c\
	src/syscall/sys.c\
	src/syscall/net.c\
	src/syscall/futex.c

TEST_UPROGS := \
	$(addprefix test/test_assertion/build/, fib test_fork test_thread)\
	$(addprefix test/test_stdout/build/, hello cat echo)\
	$(addprefix test/test_shell/build/, mv env gcc)

LINUX_BUILD_SERV := idylls.jp

all: build/noah

dev: CFLAGS += -DDEBUG_MODE=1 -O0
dev: build/noah

build/noah: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test/test_assertion/build/%: test/test_assertion/%.c test/include/*.h
	$(MAKE_TEST_UPROGS)
test/test_stdout/build/%: test/test_stdout/%.c test/include/*.h
	$(MAKE_TEST_UPROGS)
test/test_shell/build/%: test/test_shell/%.c test/include/*.h
	$(MAKE_TEST_UPROGS)

MAKE_TEST_UPROGS = ssh $(LINUX_BUILD_SERV) "rm /tmp/$(USER)/*";\
                   rsync $^ $(LINUX_BUILD_SERV):/tmp/$(USER)/;\
                   ssh $(LINUX_BUILD_SERV) "gcc -g -O0 /tmp/$(USER)/$*.c -lpthread -o /tmp/$(USER)/$*";\
                   rsync $(LINUX_BUILD_SERV):/tmp/$(USER)/$* $@

run: build/noah test/test_stdout/build/hello
	./build/noah test/test_stdout/build/hello
clean:
	$(RM) -r src/*.o
	$(RM) -r src/syscall/*.o
	$(RM) -r build/noah
	$(RM) test/test_assertion/build/* test/test_stdout/build/* test/test_shell/build/*

test: build/noah $(TEST_UPROGS)
	./test/test.rb

.PHONY: all run test clean
