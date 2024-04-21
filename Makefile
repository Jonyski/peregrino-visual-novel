CFLAGS= -Wall

run: all
	@echo "Running Light Novel"
	@./main.out

all: src/main.c $(wildcard modules/*.c)
	@echo "Compiling the project"
	@gcc -g src/modules/* ./src/main.c -o main.out -I ./headers

clean:
	@echo "Removing files..."
	rm main.out
