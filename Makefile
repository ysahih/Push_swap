NAME = push_swap

B_NAME = checker
HDR = push_swap.h
B_SRCS = bonus/utils/gnl.c bonus/checker.c lst_utils.c utils.c sort_utils.c moves.c main.c\

SRCS = lst_utils.c utils.c sort_utils.c moves.c main.c\


RM = rm -rf
CC = cc
OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $^

bonus : $(B_NAME) $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@$(RM) $(NAME) $(B_NAME) $(B_OBJS)

re : fclean all