ASFLAGS += -m32
CFLAGS += -g
LDFLAGS += -framework Hypervisor

all: src/injected.o build/noah

build/noah: src/main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: build/noah
	./build/noah

clean:
	$(RM) -r src/*.o
	$(RM) -r build/noah

.PHONY: all run clean
