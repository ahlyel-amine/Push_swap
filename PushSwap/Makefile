#------------------------------------------
#	Colors
#------------------------------------------

HBLK = '\e[1;90m'
HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HYEL = '\e[1;93m'
HBLU = '\e[1;94m'
HMAG = '\e[1;95m'
HCYN = '\e[1;96m'
HWHT = '\e[1;97m'
NC   = '\e[0m'

#------------------------------------------
#	Variables
#------------------------------------------
CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = push_swap.c\
	list_controll.c\
	parsing.c\

UTILS = utils.c\
		ft_split_garbg.c

CTRL_FUN = big_sort.c\
			ft_sort.c\
			low_sort.c\
			sort_tools.c

SORT_FUN = reverse_functions.c\
			swap_functions.c\
			push_functions.c\
			rotate_functions.c

NAME = bin/push_swap

BONUS = bin/checker

LIBFT = ../libft/libft.a

#------------------------------------------
#	Adding path to src functions
#------------------------------------------
SRC_PATH = $(addprefix src/, $(SRC))
UTILS_PATH = $(addprefix src/utils/, $(UTILS))
CTRL_FUN_PATH = $(addprefix src/sort_controll/, $(CTRL_FUN))
SORT_FUN_PATH = $(addprefix src/sort_functions/, $(SORT_FUN))

SRCS = ${SRC_PATH} ${UTILS_PATH} ${CTRL_FUN_PATH} ${SORT_FUN_PATH}

#------------------------------------------
#	Substitution of the text
#------------------------------------------

OBJS_a = ${SRC:.c=.o} ${UTILS:.c=.o} ${CTRL_FUN:.c=.o} ${SORT_FUN:.c=.o}
OBJS = $(addprefix obj/, $(OBJS_a))

#------------------------------------------
#	Executable
#------------------------------------------

all : $(NAME)

${NAME} : dir $(OBJS)
	make -C ../libft
	${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}
	@printf ${HGRN}"Executable $(NAME) ready ✔️"$(NC)

obj/%.o : src/%.c headers/push_swap.h
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

obj/%.o : src/sort_functions/%.c headers/push_swap.h
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

obj/%.o : src/sort_controll/%.c headers/push_swap.h
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

obj/%.o : src/utils/%.c headers/push_swap.h
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

# bonus : ${BONUS}

# ${BONUS} : ${BONUS_HEADER}
# 	${CC} ${CFLAGS} -o $(BONUS) ${BONUS_SRC}
# # @printf "\n\b${FBrown/Orange}Compiling bonus part \xF0\x9F\x95\x9D \n$(RESET)"
# # @printf "\b${FGreen}Executable $(BONUS) ready $(TICK)\n$(RESET)"

dir :
	@mkdir -p obj bin

#-----------------------------------------------#
#					Cleaning					#
#-----------------------------------------------#

clean :
	${RM} obj
	@printf ${HRED}"Object files removed successfully 🗑️ \n"$(NC)

fclean : clean
	make fclean -C ../libft
	${RM} bin
	@printf ${HRED}"Executable $(NAME) removed 🗑️\n"$(NC)

re : fclean all

.PHONY : fclean clean re bonus
.SILENT : clean fclean re all $(NAME)
