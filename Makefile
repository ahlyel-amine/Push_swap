LIBFT = \
		libft/ft_isdigit.o\
		libft/ft_strlen.o\
		# libft/ft_atoi.o\
		# libft/ft_bzero.o\
		# libft/ft_calloc.o\
		# libft/ft_isalnum.o\
		# libft/ft_isalpha.o\
		# libft/ft_isascii.o\
		# libft/ft_isprint.o\
		# libft/ft_memchr.o\
		# libft/ft_memcmp.o\
		# libft/ft_memcpy.o\
		# libft/ft_memmove.o\
		# libft/ft_memset.o\
		# libft/ft_strchr.o\
		# libft/ft_strdup.o\
		# libft/ft_strlcat.o\
		# libft/ft_strlcpy.o\
		# libft/ft_strncmp.o\
		# libft/ft_strnstr.o\
		# libft/ft_strrchr.o\
		# libft/ft_tolower.o\
		# libft/ft_toupper.o\
		# libft/ft_substr.o\
		# libft/ft_strjoin.o\
		# libft/ft_strtrim.o\
		# libft/ft_split.o\
		# libft/ft_itoa.o\
		# libft/ft_strmapi.o\
		# libft/ft_striteri.o\
		 libft/ft_putchar_fd.o\
		# libft/ft_putstr_fd.o\
		# libft/ft_putendl_fd.o\
		# libft/ft_putnbr_fd.o

PUSH_SWAP = push_swap.o\
			sort_functions.o\
			calcul_comb.o\
			\
			sort_functions/reverse_functions.o\
			sort_functions/swap_functions.o\
			sort_functions/push_functions.o\
			sort_functions/rotate_functions.o\
			\
			controllers/input_controller.o\
			controllers/lists_controllers_functions.o\
			controllers/stack_controller.o\
			controllers/sort_controller.o\
			\
			utils/utils.o\
			utils/ft_split_count.o\
			\
			longest_increasing_subsequence/lis.o\
			\

CC = cc

CFLAGS =

RM = rm -f

AR = ar -rcs

NAME = push_swap.a

all : ${NAME}

${NAME} : ${LIBFT} ${PUSH_SWAP}
	${AR} ${NAME} $^

compile : ${NAME}
	${CC} ${CFLAGS} -o push_swap ${NAME}

%.o : %.c libft.h
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	${RM} ${LIBFT} ${PUSH_SWAP} ${NAME}

fclean : clean
	${RM} push_swap

re : fclean all

.PHONY : fclean clean re
