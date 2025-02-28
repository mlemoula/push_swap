CC				=	cc
CFLAGS			=	-Wextra -Wall -Werror -I ./libft
NAME			=	push_swap
RM				=	rm -f
MAKEFILE_LIBFT	=	./libft/
LIBFT_PATH		=	./libft/libft.a

SRCS			=	./main.c \
					./parse_stack.c \
					./operations.c \
					./clean.c \
					./algo_tri_v1.c

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
