CC=clang
TARGET=d-linked
# FLAGS=-Wall -Werror -Wshadow 

all:
	$(CC) $(TARGET).c -o main 
	./main

clean:
	rm main
