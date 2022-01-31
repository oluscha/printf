.PHONY: all clean fclean re
SRCS    =   ft_printf.c				\
			ft_base.c				\
			ft_print_hex.c			\
			ft_print_ptr.c			\
			ft_print_unsigned_int.c	\
			ft_base.c				

OBJS    =   ${SRCS:.c=.o}
NAME    =   libftprintf.a
PR_HEAD =   ft_printf.h
RM      =   rm -f
CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
%.o:%.c ${PR_HEAD}
			${CC} ${CFLAGS} -c $< -o $@
${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
