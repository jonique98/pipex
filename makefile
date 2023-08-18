CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
SRCS =	$(wildcard *.c)
OBJECTS = $(SRCS:.c=.o)
INC = -I./src/
OBJ_DIR = ./obj

BNSNAME = checker
BNSSRCS = $(wildcard ./bnssrc/*.c)
BNSOBJECTS = $(BNSSRCS:.c=.o)
GNLINC = -I./bnssrc/

RMF = rm -f

all : $(NAME)

bonus : $(BNSNAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BNSNAME) : $(BNSOBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

bnssrc/%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INC) $(GNLINC)

clean :
	$(RMF) $(OBJECTS) $(BNSOBJECTS)

fclean : clean
	$(RMF) $(NAME) $(BNSNAME)

re : fclean all

.PHONY : clean fclean all re bonus