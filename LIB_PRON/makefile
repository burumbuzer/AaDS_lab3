.PHONY: all clean fclean

CC = gcc

TARGET = str_to_tree_ws
SRC = str_to_tree_ws.c $(wildcard LIB_PRON/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET) clean

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.c
	$(CC) -c -o $@ $<

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(TARGET)