CFLAGS += -g -Iinclude -std=gnu11
LDFLAGS += -framework Hypervisor -lpthread

SRCS := \
	lib/vmm.c\
	src/main.c\
	src/meta_strace.c\
	src/common.c\
	src/debug.c\
	src/proc/exec.c\
	src/proc/fork.c\
	src/proc/process.c\
	src/net/net.c\
	src/ipc/futex.c\
	src/ipc/signal.c\
	src/fs/fs.c\
	src/sys/sys.c\
	src/sys/time.c\
	src/mm/mm.c\
	src/mm/mmap.c\
	src/mm/malloc.c

TEST_UPROGS := \
	$(addprefix test/test_assertion/build/, fib test_fork test_thread test_execve)\
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
                   ssh $(LINUX_BUILD_SERV) "gcc -std=gnu99 -g -O0 /tmp/$(USER)/$*.c -lpthread -o /tmp/$(USER)/$*";\
                   rsync $(LINUX_BUILD_SERV):/tmp/$(USER)/$* $@

run: build/noah test/test_stdout/build/hello
	./build/noah test/test_stdout/build/hello
clean:
	$(RM) -r lib/*.o src/*.o src/*/*.o
	$(RM) -r build/noah
	$(RM) test/test_assertion/build/* test/test_stdout/build/*
	$(RM) `ls test/test_shell/build/* | grep -v gcc`

test: build/noah $(TEST_UPROGS)
	./test/test.rb

.PHONY: all run test clean
