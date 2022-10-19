CC=clang
TARGET=linked

all:
	$(CC) $(TARGET).c -o main
	./main

clean:
	rm $(TARGET)
