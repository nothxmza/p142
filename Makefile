NAME		=	philo

FIL_M		=	main.c \
				utils.c \
				parsing.c \
				init.c

OBJ_M		=	$(FIL_M:.c=.o)

CC			=	gcc
CFLAG		=	
RM			=	rm -f
MAKE		=	make

%.o			:	%.c
			$(CC) $(CFLAG) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJ_M)
			$(CC) $(OBJ_M) $(CFLAG) -lpthread -o $(NAME)

bonus		:	$(all)

clean		:
			$(RM) $(OBJ_M)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all
