CC = g++

# -std=++20  main.cpp -c -lglfw -lGLEW -lGLESv2

all: compile glad final

compile:
		make -f graphics/Makefile 

glad:
	$(CC) -std=c++20 -c src/glad.c

final:
	$(CC) -std=c++20 core/main.cpp render.o shaders.o glad.o -lglfw -lGLEW -lGLESv2 -o final
