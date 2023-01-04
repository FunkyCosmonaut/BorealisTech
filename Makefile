CC = g++

# -std=++20  main.cpp -c -lglfw -lGLEW -lGLESv2

all: glad compile final

compile:
		make -f graphics/Makefile 

glad:
	$(CC) -std=c++20 -c src/glad.c

final:
	$(CC) -std=c++20 core/main.cpp render.o shaders.o glad.o -lglfw -lGLESv2 -o final

clean:
	rm final render.o shaders.o glad.o
