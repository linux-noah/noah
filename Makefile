LDFLAGS += -framework Hypervisor

all: build/noah

build/noah: src/main.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

run: build/noah
	./build/noah

clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah

.PHONY: all run clean
