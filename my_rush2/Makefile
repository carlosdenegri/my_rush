# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cadenegr <cadenegr@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 14:55:14 by cadenegr          #+#    #+#              #
#    Updated: 2023/08/14 15:24:06 by cadenegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= rush.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

# Sources

SRC_FILES	=	?????

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)
				@echo "ft_printf compiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
				@echo "Compiling:"
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@$(RM) -f $(NAME)
				@$(RM) -f ./main
				@make clean -C $(LIBFT)
				@echo "Objects files and library files cleaned!"

fclean:		clean
				@$(RM) -f $(NAME)
				@$(RM) -f $(LIBFT)/libft.a
				@echo "Rush executable files cleaned!"
				@echo "libft executable files cleaned!"

re:				fclean all
				@echo "Cleaned and rebuilt everything for Rush!"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
