TARGET = monty
OBJECTS = *.c
HFILE = monty.h
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

$(TARGET) : $(OBJECTS)
	gcc $(OBJECTS) $(CFLAGS) -o $(TARGET)
