CC=clang
TARGET=linked_queue
# FLAGS=-Wall -Werror -Wshadow 

all:
	$(CC) $(TARGET).c -o main 
	./main

clean:
	rm main
