CC=clang
TARGET=stack

all:
	$(CC) $(TARGET).c -o main
	./main

clean:
	rm $(TARGET)
