CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS = $(shell pkg-config --libs glfw3 || pkg-config --libs glfw) -lGL -ldl -lpthread -lm -lX11 
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/BorealisTech
SOURCES = $(wildcard $(SRCDIR)/*.cpp) $(SRCDIR)/glad.c
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(filter %.cpp,$(SOURCES))) \
          $(OBJDIR)/glad.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/glad.o: $(SRCDIR)/glad.c
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*

run: $(TARGET)
	$(TARGET)
