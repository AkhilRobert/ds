CC=clang
TARGET=queue

all:
	$(CC) $(TARGET).c -o main
	./main

clean:
	rm $(TARGET)
