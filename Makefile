# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:11:58 by ggomes-v          #+#    #+#              #
#    Updated: 2025/02/04 13:30:10 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
FT_PRINTF = includes/ft_printf/ft_printf.c\
			includes/ft_printf/ft_putstr.c\
			includes/ft_printf/ft_putnbr.c\
			includes/ft_printf/ft_unsigned_int.c\
			includes/ft_printf/ft_hexadecimal.c\
			includes/ft_printf/ft_pointeraddress.c\
			includes/ft_printf/ft_putchar.c\

LIBFT = includes/libft/ft_split.c\
		includes/libft/ft_atoi.c\
		includes/libft/ft_putchar_fd.c\
		includes/libft/ft_putstr_fd.c\
		includes/libft/ft_putnbr_fd.c\
		includes/libft/ft_putendl_fd.c\
		includes/libft/ft_atol.c\
		includes/libft/ft_lstsize.c\

SRCS = push_swap.c\
		ft_checks.c\
		lst.c\
		utils.c\
		simple_sort.c\
		main_sort.c\
		case_calculation.c\
		case_calculation2.c\
		apply_cases.c\
		rotate_type.c\
		instructions.c\
		instructions2.c\
		instructions3.c\
		index.c\

ALL_SRCS = $(SRCS) $(FT_PRINTF) $(LIBFT) 

NAME = push_swap
RM = rm -rf 
OBJS = $(ALL_SRCS:.c=.o)

all:${NAME}

${NAME}:${OBJS}
	@${CC} ${CFLAGS} ${ALL_SRCS} -o ${NAME}
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ ✅ |${GREEN}All Files Compiled${RESET}     ║"
	@echo "	╚═════════════════════════════════════╝"  

%.o: %.c
	@echo "${GREEN}${BOLD}✅ | Compiling $<...${RESET}"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS} 
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${BOLD}Cleaned Successfully!${RESET}   ║"
	@echo "	╚═════════════════════════════════════╝"
 
fclean: clean
	@${RM} ${NAME}
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${CYAN}Full Clean Done!${RESET}    ║"
	@echo "	╚═════════════════════════════════════╝"
 

re: fclean all
.PHONY: all clean fclean re

RESET = \033[0m      
BOLD = \033[1m  
RED = \033[31m      
GREEN = \033[32m   
YELLOW = \033[33m  
BLUE = \033[34m     
MAGENTA = \033[35m   
CYAN = \033[36m      
WHITE = \033[37m