CC = g++

# -std=++20  main.cpp -c -lglfw -lGLEW -lGLESv2

final:
	$(CC) -std=c++20 core/main.cpp graphics/render.o -lglfw -lGLEW -lGLESv2 -o final