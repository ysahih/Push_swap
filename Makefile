NAME = push_swap

B_NAME = checker
HDR = push_swap.h
B_SRCS = bonus/utils/gnl.c bonus/checker.c lst_utils.c utils.c sort_utils.c moves.c utils___.c\

SRCS = lst_utils.c utils.c sort_utils.c utils___.c moves.c main.c\


RM = rm -rf
CC = cc
OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all : $(NAME)

bonus : $(B_NAME) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $^


%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@$(RM) $(NAME) $(B_NAME)

re : fclean all