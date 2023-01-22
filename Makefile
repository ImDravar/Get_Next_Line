# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 18:00:28 by rruiz-sa          #+#    #+#              #
#    Updated: 2023/01/22 18:02:08 by rruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#  .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.      .-.    #
# 42BCN\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\  42BCN\   #
# '     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'        #

NAME = libget_next_line.a

# //-=-=-=-/-=-=-=-//-=-=-=-//-=-=-=-//COLORS//-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//#

WHITE	= \033[97m
GREEN	= \033[92m
RED		= \033[91m
CYAN	= \033[96m
YELLOW	= \033[93m
DEF_CL	= \033[m

# //-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//COMAND//-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//#


CFLAGS 	= -Wall -Wextra -Werror

RM 		= rm -f

NORM 	= norminette -R CheckForbiddenSourceHeader .

AR		= ar -rcs

# //-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//-FILES//-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//#

HEADER = get_next_line.h

SRC =

OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

# //-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//-RULES//-=-=-=-//-=-=-=-//-=-=-=-//-=-=-=-//#

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -MMD -I ./ -c $< -o $@
	@echo "$(WHITE)	Compiling: $(CYAN)$< $(DEF_CL)"

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
	@$(AR)  $(NAME) $(OBJ)
	@echo "Compilation $(GREEN) Completed ! $(DEF_CL)"

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "$(WHITE)	Deleted objects: $(RED)$(OBJ) $(OBJ_BONUS) $(DEF_CL)"
	@$(RM) $(DEPS) $(DEPS_BONUS)
	@echo "$(WHITE)	Deleted dependencies: $(RED)$(DEPS) $(DEPS_BONUS) $(DEF_CL)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(WHITE)	Deleted: $(RED)$(NAME) $(DEF_CL)"

re: fclean all

norm:
	@echo "$(YELLOW)Norminette says:  $(DEF_CL)"
	@$(NORM)

.PHONY: all clean fclean re norm bonus

#  .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.      .-.   #
# 42BCN\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\42_RuRu\  42BCN\  #
# '     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'       #