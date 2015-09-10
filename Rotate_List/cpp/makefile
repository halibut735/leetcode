CC  = g++
CFLAGS  += -g -Wall
CFLAGS  += $(OPTFLAGS)
SRCS := $(wildcard ./src/*cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SRCS))
HEADS := $(wildcard ./inc/*.h)
TARGET  := main

INCS    = -I./inc -I/Users/bingoboy/projects/github/leetcode/Rotate_List/cpp/inc
LIB =

LIBPATH += ./lib
BINPATH := ./bin
vpath %.cpp src
vpath %.c src
vpath %.h inc

%.o:%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
%.o:%.cpp
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

.PHONY: all clean

all:$(SUPPORT) $(TARGET)
$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $^
	rm -f $(OBJECTS)
	mv $(TARGET) $(BINPATH)

clean:
	rm -f   $(OBJECTS)