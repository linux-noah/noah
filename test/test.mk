TEST_UPROGS := \
	$(addprefix test_assertion/build/, fib test_fork test_thread test_execve test_execve2)\
	$(addprefix test_stdout/build/, hello cat echo)\
	$(addprefix test_shell/build/, mv env gcc)

LINUX_BUILD_SERV := idylls.jp

test: $(TEST_UPROGS)
	./test.rb $(NOAH)

test_assertion/build/%: test_assertion/%.c include/*.h
	$(MAKE_TEST_UPROGS)
test_stdout/build/%: test_stdout/%.c include/*.h
	$(MAKE_TEST_UPROGS)
test_shell/build/%: test_shell/%.c include/*.h
	$(MAKE_TEST_UPROGS)

MAKE_TEST_UPROGS = ssh $(LINUX_BUILD_SERV) "rm /tmp/$(USER)/*";\
                   rsync $^ $(LINUX_BUILD_SERV):/tmp/$(USER)/;\
                   ssh $(LINUX_BUILD_SERV) "gcc -std=gnu99 -g -O0 /tmp/$(USER)/$*.c -lpthread -o /tmp/$(USER)/$*";\
                   rsync $(LINUX_BUILD_SERV):/tmp/$(USER)/$* $@

clean:
	$(RM) test_assertion/build/* test_stdout/build/*
	$(RM) `ls test_shell/build/* | grep -v gcc`

.PHONY: test clean
