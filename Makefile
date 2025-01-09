# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:11:58 by ggomes-v          #+#    #+#              #
#    Updated: 2025/01/07 11:27:49 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE
SRCS = push_swap.c ft_error.c ft_checks.c

NAME = push_swap.a
PRIC = ar rcs
RM = rm -f 
OBJS = $(SRCS:.c=.o)

${NAME}:${OBJS}
		${PRIC} ${NAME} ${OBJS}
		cc push_swap.c push_swap.a
		@echo "	╔═════════════════════════════════════╗"
		@echo "	║ ✅ |${GREEN}All Files Compiled${RESET}     ║"
		@echo "	╚═════════════════════════════════════╝"
		
%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

RESET = \033[0m      
BOLD = \033[1m   
RED = \033[31m      
GREEN = \033[32m   
YELLOW = \033[33m  
BLUE = \033[34m     
MAGENTA = \033[35m   
CYAN = \033[36m      
WHITE = \033[37m  

all:${NAME} 

clean:
		${RM} ${OBJS}
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${BOLD}Cleaned Successfully!${RESET}  ║"
	@echo "	╚═════════════════════════════════════╝"
 
fclean: clean
		${RM} ${NAME} a.out
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${CYAN}Full Clean Done!${RESET}    ║"
	@echo "	╚═════════════════════════════════════╝"
 

re: fclean all
.PHONY: all clean fclean re