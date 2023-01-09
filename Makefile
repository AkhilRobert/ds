CC=clang
TARGET=bst
# FLAGS=-Wall -Werror -Wshadow 

all:
	$(CC) $(TARGET).c -o main 
	./main

clean:
	rm main
