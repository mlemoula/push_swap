CC				=	cc
CFLAGS			=	-Wextra -Wall -Werror -I ./libft
NAME			=	push_swap
RM				=	rm -f
MAKEFILE_LIBFT	=	./libft/
LIBFT_PATH		=	./libft/libft.a

SRCS			=	./main.c \
					./ft_atoi_custom.c \
					./parse_stack.c \
					./operations_rotate.c \
					./operations_push_swap.c \
					./clean.c \
					./first_sort.c \
					./big_sort.c \
					./index_max.c \
					./print_ope.c

OBJS			=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_PATH)
				$(CC) $(OBJS) -o $(NAME) -L./libft -lft

$(LIBFT_PATH):	
				make -C $(MAKEFILE_LIBFT)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:			
				make clean -C $(MAKEFILE_LIBFT)
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C $(MAKEFILE_LIBFT)
				$(RM) $(NAME)

re: 			fclean all
