LDFLAGS += -framework Hypervisor

all: build/noah

build/noah: src/main.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

run: build/noah
	./build/noah

clean:
	rm -rf src/*.o
	rm -rf build/noah

.PHONY: all run clean
