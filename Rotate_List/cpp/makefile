CC  = g++
CFLAGS  += -g -Wall
CFLAGS  += $(OPTFLAGS)
SRCS := $(wildcard ./src/*cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SRCS))
TARGET  := aa

INCS    = -I./inc
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

all:$(SUPPORT) $(TARGET)
$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $^
	rm -f $(OBJECTS)
	mv $(TARGET) $(BINPATH)

.PHONY: all clean

clean:
	rm -f   $(OBJECTS)
