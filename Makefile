CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putnbr_base.c \
		ft_putunsigned.c \
		ft_hex.c \

OBJ = ${CFILES:.c=.o}

RM = rm -rf
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)

${OBJ} :  $(CFILES)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	ar -crs $(NAME) $@

clean :
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all