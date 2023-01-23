LIBFT = \
		# libft_tools/ft_isdigit.o\
		# libft_tools/ft_strlen.o\
		# libft_tools/ft_lstlast.o\
		# libft_tools/ft_lstadd_back.o\
		# libft_tools/ft_lstdelone.o\
		# libft_tools/ft_lstclear.o\
		# libft_tools/ft_lstnew.o\
		# libft_tools/ft_putendl_fd.o\
		# libft_tools/ft_putstr_fd.o\
		# libft_tools/ft_substr.o\
		# libft_tools/ft_calloc.o\
		# libft_tools/ft_memcpy.o\
		# libft_tools/ft_strdup.o\
		# libft_tools/ft_bzero.o\
		# libft_tools/ft_memset.o\

BONUS_FUNCS =	bonus/checker\
				bonus/ft_split_garbg\
				bonus/list_controll\
				bonus/parsing\
				bonus/utils\
				bonus/get_next_line/get_next_line_utils\
				bonus/get_next_line/get_next_line\
				bonus/sort_functions/reverse_functions\
				bonus/sort_functions/swap_functions\
				bonus/sort_functions/push_functions\
				bonus/sort_functions/rotate_functions\
				bonus/libft_tools/ft_isdigit\
				bonus/libft_tools/ft_strlen\
				bonus/libft_tools/ft_lstlast\
				bonus/libft_tools/ft_lstadd_back\
				bonus/libft_tools/ft_lstdelone\
				bonus/libft_tools/ft_lstclear\
				bonus/libft_tools/ft_lstnew\
				bonus/libft_tools/ft_putendl_fd\
				bonus/libft_tools/ft_putstr_fd\
				bonus/libft_tools/ft_substr\
				bonus/libft_tools/ft_calloc.o\
				bonus/libft_tools/ft_memcpy.o\
				bonus/libft_tools/ft_strdup.o\
				bonus/libft_tools/ft_bzero.o\
				bonus/libft_tools/ft_memset.o\

BONUS_HEADER =	bonus/checker.h
BONUS_OBJ = ${BONUS_FUNCS:=.o}
BONUS_SRC = ${BONUS_FUNCS:=.c}

PUSH_SWAP = push_swap.o\
			\
			list_controll.o\
			utils/utils.o\
			parsing.o\
			ft_split_garbg.o\
			sort_controll/big_sort.o\
			sort_controll/ft_sort.o\
			sort_controll/low_sort.o\
			sort_controll/sort_tools.o\
			controllers/stack_controller.o\
			sort_functions/reverse_functions.o\
			sort_functions/swap_functions.o\
			sort_functions/push_functions.o\
			sort_functions/rotate_functions.o\
			libft_tools/ft_isdigit.o\
			libft_tools/ft_strlen.o\
			libft_tools/ft_lstlast.o\
			libft_tools/ft_lstadd_back.o\
			libft_tools/ft_lstdelone.o\
			libft_tools/ft_lstclear.o\
			libft_tools/ft_lstnew.o\
			libft_tools/ft_putendl_fd.o\
			libft_tools/ft_putstr_fd.o\
			libft_tools/ft_substr.o\
			libft_tools/ft_calloc.o\
			libft_tools/ft_memcpy.o\
			libft_tools/ft_strdup.o\
			libft_tools/ft_bzero.o\
			libft_tools/ft_memset.o\

# Black           =   $(shell echo "\033[0;30m")
# FBlack          =   $(shell echo "\033[1;30m")
# Red             =   $(shell echo "\033[0;31m")
FRed            =   $(shell echo "\033[1;31m")
# Green           =   $(shell echo "\033[0;32m")
FGreen          =   $(shell echo "\033[1;32m")
# Brown/Orange    =   $(shell echo "\033[0;33m")
FBrown/Orange   =   $(shell echo "\033[1;33m")
# FYellow         =   $(shell echo "\033[1;33m")
# Yellow          =   $(shell echo "\033[0;33m")
# Blue            =   $(shell echo "\033[0;34m")
# FBlue           =   $(shell echo "\033[1;34m")
# Purple          =   $(shell echo "\033[0;35m")
# FPurple         =   $(shell echo "\033[1;35m")
# Cyan            =   $(shell echo "\033[0;36m")
# FCyan           =   $(shell echo "\033[1;36m")
# FWhite          =   $(shell echo "\033[1;37m")
# White           =   $(shell echo "\033[0;37m")
RESET           =   $(shell echo "\033[0m")
TICK            =   $(shell echo "\xE2\x9C\x94")

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

all : ${NAME}

${NAME} : ${PUSH_SWAP}
	@printf "\n\b${FBrown/Orange}Compiling $(NAME) \xF0\x9F\x95\x9D \n$(RESET)"
	@${CC} ${CFLAGS} -o push_swap ${PUSH_SWAP}
	@printf "\b${FGreen}Executable $(NAME) ready $(TICK)\n$(RESET)"

%.o : %.c
	@${CC} ${CFLAGS} -c -o $@ $<

bonus : ${BONUS_SRC} ${BONUS_HEADER}
	@{CC} ${CFLAGS} -o checker ${BONUS_SRC}
# @${CC} ${CFLAGS} -o ${GET_NEXT_LINE_OBJ} ${GET_NEXT_LINE_SRC}

%.o : %.c
	@${CC} ${CFLAGS} -c -o ${BONUS_SRC} ${BONUS_OBJ}

clean :
	@printf "\b${FGreen}Removing object files \xF0\x9F\x95\x9D ${BONUS_OBJ} \n$(RESET)"
	@${RM} ${LIBFT} ${PUSH_SWAP} ${BONUS_OBJ}
	@printf "\b${FRed}Object files removed successfully 🗑️ \n$(RESET)"

fclean : clean
	@printf "\b${FGreen}\nRemoving executable $(NAME) \xF0\x9F\x95\x9D \n$(RESET)"
	@${RM} push_swap
	@printf "\b${FRed}Executable $(NAME) removed 🗑️\n$(RESET)"

re : fclean all

.PHONY : fclean clean re bonus
