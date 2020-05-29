NAME	= my_runner

CC	= gcc

RM	= rm -f

SRCS	= src/./main.c \
	  src/./thegame.c \
	  src/./gameover.c \
	  src/./win.c \
	  src/./my_putstr.c \
	  src/./nb_tochar.c \
	  src/./my_putchar.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -l csfml-system -l csfml-audio -l csfml-graphics -l csfml-network -l csfml-window


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
