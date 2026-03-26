.PHONY: all clean fclean

CC = gcc
FLAGS = -g

TARGET = main
SRC = main.c $(wildcard LIB_PRON/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET) clean

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(TARGET)
