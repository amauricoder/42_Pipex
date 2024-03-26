# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 16:42:51 by aconceic          #+#    #+#              #
#    Updated: 2024/03/26 17:29:58 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################################
#                  COLORS                    #
##############################################
GREEN = \033[0;32m
BLUE = \033[1;34m
RED = \033[0;31m
MAGENTA = \033[1;35m
ORANGE = \033[38;5;208m
RESET = \033[0m

##############################################
#                  COMMANDS                  #
##############################################
MAKEC = make -C
MAKECLEANC = make clean -C
RM = rm -rf

##############################################
#                 MAIN SOURCES               #
##############################################
### Libraryes
LIBFT_DIR = libraries/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
GNL_DIR = $(LIBFT_DIR)get_next_line/
GNL_LIB = $(GNL_DIR)gnl.a

### Project
NAME = pipex
OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRC_DIR = ./source/
SRC = pipex_redirect.c error_handling.c pipex_execute.c ft_utils.c \

##############################################
#                 BONUS SOURCES              #
##############################################
BONUS_NAME = pipex_bonus
BONUS_OBJ_DIR = bonus/bonus_obj/
BONUS_SRC = bonus/main_bonus.c \

BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC:bonus/%.c=%.o))
##############################################
#                COMPILATION                 #
##############################################
CC = cc
GCC = cc -g
CFLAGS = -Wall -Wextra -Werror

################################################################
#                   		   RULES            			   #
#               			MAIN PROJECT     			       #
################################################################

all : $(NAME)

$(OBJ) : | $(OBJ_DIR)

$(OBJ_DIR) :
	@echo "$(ORANGE)[!]$(RESET) Creating directory for objects ..."
	mkdir $@

$(NAME) : $(OBJ) $(LIBFT_LIB)
	@echo "$(ORANGE)[!]$(RESET) Working on project ... "
	$(GCC) $(CFLAGS) $(OBJ) $(SRC_DIR)main.c $(LIBFT_LIB) $(GNL_LIB) -o $(NAME)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Ok!$(RESET) "

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(ORANGE)[!]$(RESET) Creating objects ..."
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Objects Ok!$(RESET) "

$(LIBFT_LIB) : $(LIBFT_DIR)
	@echo "$(ORANGE)[!]$(RESET) Working on LIBFT_LIB ..."
	$(MAKEC) $(LIBFT_DIR) bonus
	$(MAKEC) $(PRINTF_DIR)
	$(MAKEC) $(GNL_DIR)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)LIBFT Ok!$(RESET)"

clean :
	@echo "$(ORANGE)[!]$(RESET) Executing cleaning ..."
	$(RM) $(OBJ_DIR)
	$(RM) $(BONUS_OBJ_DIR)
	$(MAKECLEANC) $(LIBFT_DIR)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Cleaning Ok!$(RESET) "

fclean :
	@echo "$(ORANGE)[!]$(RESET) Executing full cleaning..."
	$(RM) $(NAME) $(OBJ_DIR)
	$(RM) $(BONUS_NAME) $(BONUS_OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)full cleaning!$(RESET) "

re : fclean all
	@echo "$(GREEN)[✔]$(RESET) $(MAGENTA)Refresh Ok!$(RESET) "

.SILENT: all
################################################################
#                   		   RULES            			   #
#               			   BONUS     			           #
################################################################

bonus : $(BONUS_NAME)

$(BONUS_OBJ_DIR) :
	@echo "$(YELLOW)[!] $(RESET)CREATING DIRECTORY FOR BONUS OBJECTS"
	@mkdir $@
	@echo "$(GREEN)[✔]$(RESET) CREATED $@ DIRECTORY"

# Rule to compile bonus objects
$(BONUS_OBJ_DIR)%.o : bonus/%.c | $(BONUS_OBJ_DIR)
	@echo "$(YELLOW)[!] $(RESET)COMPILING BONUS OBJ $< "
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[✔]$(RESET) BONUS OBJ COMPILED $<"

$(BONUS_NAME) : $(BONUS_OBJ_DIR) $(BONUS_OBJ) $(OBJ) $(LIBFT_LIB)
	@echo "$(YELLOW)[!] $(RESET)COMPILING BONUS "
	$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBFT_LIB) $(GNL_LIB) -o $(BONUS_NAME)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)OK$(RESET)"
	
bre : fclean bonus
	@echo "$(GREEN)[✔]$(RESET) $(MAGENTA)BONUS Refresh Ok!$(RESET) "