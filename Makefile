NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

SRCS = srcs/

FILES = ft_printf.c          \
		ft_put_adr.c         \
		ft_putchar_fd.c      \
		ft_putnbr_basediu.c  \
		ft_putstr_fd.c       \
		ft_Xxconvert_basexX.c\

OBJ = ${FILES:.c=.o}

all :	${NAME}

libftprintf.a : 	${OBJ}
			ar rc ${NAME} ${OBJ}
%.o:		%.c libft.h
			$(CC) $(CFLAGS) -c $< -o $@
clean :
			rm -f ${OBJ}
fclean :	clean
			rm -f ${NAME}
re :		fclean all

.PHONY:		all clean fclean libft.a .c.o re
