NAME := push_swap

COMPILER := cc

FLAGS := -Wall -Wextra -Werror

SRCS := ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstclear.c\
ft_lstdelone.c\
ft_lstlast.c\
ft_lstnew.c\
ft_lstsize.c\
main.c\
push_swap_utils.c\
push_swap.c\
swap_push_rotate.c\
easy_sort.c\
errors.c

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) push_swap.h
	@cd Libft && $(MAKE) --no-print-directory
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS) ./Libft/libft.a

clean:
	@cd Libft/ && $(MAKE) --no-print-directory fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
