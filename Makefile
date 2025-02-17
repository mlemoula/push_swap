CC				=	cc
CFLAGS			=	-Wextra -Wall -Werror
#-I ./libft
# NAME			=	libftprintf.a
NAME			=	push_swap
RM				=	rm -f
# MAKEFILE_LIBFT	=	./libft/
# LIBFT_PATH		=	./libft/libft.a

SRCS			=	./main.c

OBJS			=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# $(LIBFT_PATH):
# 				make -C $(MAKEFILE_LIBFT)

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all
