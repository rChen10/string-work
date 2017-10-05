all: string.c header.h
	gcc string.c -o stringtest
run: all
	./stringtest
