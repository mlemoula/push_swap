CC= 		cc

CFLAGS = 	-Wall -Wextra -Werror

SRCS = 		./ft_lstadd_front.c \
			./ft_lstadd_back.c \
			./ft_lstnew.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_split.c \
			./ft_strlen.c
				
OBJS = 		$(SRCS:.c=.o)

NAME = 		libft.a

all: 		$(NAME)

$(NAME): 	$(OBJS)
			ar -rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS) $(OBJSBONUS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

bonus:		$(OBJS) $(OBJSBONUS)
			ar -rc $(NAME) $(OBJS) $(OBJSBONUS)