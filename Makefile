CFLAGS= -Wall

run: main.out
	@echo "Running Light Novel"
	@./$<

main.out: src/main.c $(wildcard src/modules/*.c)
	@echo "Compiling the project"
	@gcc $(CFLAGS) -g $^ -o $@ -I ./headers -lpthread

clean:
	@echo "Removing files..."
	rm ./main.out
