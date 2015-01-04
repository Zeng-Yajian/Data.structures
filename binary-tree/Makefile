INCLUDE_FLAGS = -I.
CFLAGS	      = $(INCLUDE_FLAGS) -Wall -g
CC			  = gcc

TARGET = bst_demo
LIB = libbst

all: $(TARGET) $(LIB)

SOUCE_FILES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOUCE_FILES))

%.o : %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(LIB): $(OBJS)
	ar -r $(LIB) $(OBJS)



.PHONY:clean
clean:
	rm -rf $(TARGET) *.o
