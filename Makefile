CC = g++
CFLAGS = -Wall -g -std=c++17
LINKER_FLAGS = -lm
OBJS = test.cpp sha256.cpp utils.cpp
TARGET = test


all: test.o sha256.o utils.o
	$(CC) $(OBJS) $(CFLAGS) $(LINKER_FLAGS) -o $(TARGET) 
	./$(TARGET)

clean: 
	rm -r test