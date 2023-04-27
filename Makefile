NAME = push_swap

B_NAME = checker
HDR = push_swap.h
B_SRCS = bonus/utils/gnl.c bonus/checker.c\
parsing/parse.c\
parsing/parse_1.c\
parsing/parse_2.c\
core/moves.c\
core/core_utils.c\
utils/lst_utils.c\
utils/utils.c\
utils/utils_1.c\

SRCS = main.c\
parsing/parse.c\
parsing/parse_1.c\
parsing/parse_2.c\
utils/lst_utils.c\
utils/utils.c\
utils/utils_1.c\
core/chunk.c\
core/core_utils.c\
core/moves.c\
core/push_back.c\
core/sort_utils.c\



RM = rm -rf
CC = cc
OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

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