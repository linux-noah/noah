all: build/noah

build/noah: src/main.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf src/*.o
	rm -rf build/noah
