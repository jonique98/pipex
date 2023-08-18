CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
SRCS = $(wildcard *.c)
OBJ_DIR = ./obj
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC = -I ./

RMF = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RMF) obj

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: clean fclean all re
