CC = g++

# -std=++20  main.cpp -c -lglfw -lGLEW -lGLESv2

all: compile final

compile:
		make -f graphics/Makefile

final:
	$(CC) -std=c++20 core/main.cpp render.o -lglfw -lGLEW -lGLESv2 -o final