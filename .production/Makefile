#-------------------------------------------#
#					Colors					#
#-------------------------------------------#

HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HBLU = '\e[1;94m'
NC   = '\e[0m'

#-----------------------------------------------#
#				Bonus Variables					#
#-----------------------------------------------#

BONUS_SRC =	checker.c\
			list_controll.c\
			sort_tools.c\
			parsing.c\

BONUS_UTILS =	utils.c\
				push_swap.c\
				ft_split_garbg.c


BONUS_SORT_FUN =	reverse_functions.c\
					swap_functions.c\
					push_functions.c\
					rotate_functions.c

BONUS_LIBA = bonus/lib/libft/bin/libft.a
BONUS_LIBFT = bonus/lib/libft

GNL = bonus/lib/get_next_line

GNLA = bonus/lib/get_next_line/bin/get_next_line.a

BONUS = bonus/bin/checker

bonus_dir = bonus/bin bonus/obj

BONUS_INCLUDE = bonus/include/checker.h

#-------------------------------------------#
#	Adding path to bonus src functions		#
#-------------------------------------------#

BONUS_SRC_PATH = $(addprefix bonus/src/, $(BONUS_SRC))
BONUS_UTILS_PATH = $(addprefix bonus/src/utils/, $(BONUS_UTILS))
BONUS_SORT_FUN_PATH = $(addprefix bonus/src/sort_functions/, $(BONUS_SORT_FUN))

BONUS_SRCS = ${BONUS_SRC_PATH} ${BONUS_UTILS_PATH} ${BONUS_SORT_FUN_PATH}

#-----------------------------------------------#
#			Substitution of bonus objs			#
#-----------------------------------------------#

BONUS_OBJS_O = ${BONUS_SRC:.c=.o} ${BONUS_UTILS:.c=.o} ${BONUS_SORT_FUN:.c=.o}
BONUS_OBJS = $(addprefix bonus/obj/, $(BONUS_OBJS_O))


#-------------------------------------------#
#			Mandatory Variables				#
#-------------------------------------------#

SRC =	push_swap.c\
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

LIBA = lib/libft/bin/libft.a
LIBFT = lib/libft

NAME = bin/push_swap

dir = bin obj

#-------------------------------------------#
#	Adding path to mandatory src functions	#
#-------------------------------------------#

SRC_PATH = $(addprefix src/, $(SRC))
UTILS_PATH = $(addprefix src/utils/, $(UTILS))
CTRL_FUN_PATH = $(addprefix src/sort_controll/, $(CTRL_FUN))
SORT_FUN_PATH = $(addprefix src/sort_functions/, $(SORT_FUN))

SRCS = ${SRC_PATH} ${UTILS_PATH} ${CTRL_FUN_PATH} ${SORT_FUN_PATH}

#-------------------------------------------#
#		Substitution of mandatory objs		#
#-------------------------------------------#

OBJS_O = ${SRC:.c=.o} ${UTILS:.c=.o} ${CTRL_FUN:.c=.o} ${SORT_FUN:.c=.o}
OBJS = $(addprefix obj/, $(OBJS_O))

#-----------------------------------------------#
#				tools Variables					#
#-----------------------------------------------#

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCLUDE = include/push_swap.h

#---------------------------------------#
#				Executable				#
#---------------------------------------#

all : $(NAME)

${NAME} : ${dir} $(OBJS)
	make -C ${LIBFT}
	${CC} ${CFLAGS} ${LIBA} ${OBJS} -o ${NAME}
	printf ${HGRN}"Executable $(NAME) ready ✔️"$(NC)

obj/%.o : src/%.c ${INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

obj/%.o : src/sort_functions/%.c ${INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

obj/%.o : src/utils/%.c ${INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

obj/%.o : src/sort_controll/%.c ${INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

${dir} :
	mkdir -p ${dir}

#---------------------------------------------------#
#						Bonus						#
#---------------------------------------------------#

bonus :${BONUS}

${BONUS} : ${bonus_dir} ${BONUS_OBJS}
	make -C ${BONUS_LIBFT}
	make -C ${GNL}
	${CC} ${CFLAGS} -fsanitize=address ${BONUS_OBJS} ${BONUS_LIBA} ${GNLA} -o ${BONUS}
	printf ${HGRN}"Executable $(BONUS) ready ✔️"$(NC)

bonus/obj/%.o : bonus/src/%.c ${BONUS_INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

bonus/obj/%.o : bonus/src/sort_functions/%.c ${BONUS_INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

bonus/obj/%.o : bonus/src/utils/%.c ${BONUS_INCLUDE}
	@printf ${HBLU}"[%-30s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	@ ${CC} ${CFLAGS} -c $< -o $@

${bonus_dir} :
	mkdir -p ${bonus_dir}

#-----------------------------------------------#
#					Cleaning					#
#-----------------------------------------------#

clean :
	make clean -C ${LIBFT}
	make clean -C ${BONUS_LIBFT}
	make clean -C ${GNL}
	${RM} obj bonus/obj
	printf ${HRED}"Object files removed successfully 🗑️ \n"$(NC)

fclean : clean
	make fclean -C ${LIBFT}
	make fclean -C ${BONUS_LIBFT}
	make fclean -C ${GNL}
	${RM} bin bonus/bin
	printf ${HRED}"Executables and Archives removed successfully 🗑️\n"$(NC)

re : fclean all

.PHONY : fclean clean re bonus
.SILENT : clean fclean re all $(NAME) bonus ${BONUS} ${bonus_dir} ${dir}
