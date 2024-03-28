.SILENT:
.PHONY: all clean

all:
	gcc -std=c17 -o main main.c -lm -lpthread && ./main

clean:
	$(RM) main