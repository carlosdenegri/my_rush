# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 15:45:39 by cadenegr          #+#    #+#              #
#    Updated: 2023/06/28 13:23:29 by cadenegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OUTPUT = OUTPUT

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUSSRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUSSRC:.c=.o)

# Default rule
all: $(NAME)

# Rule for creating the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule for cleaning object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Rule for cleaning object files and the library
fclean: clean
	rm -f $(NAME) $(OUTPUT)

# Rule for recompiling everything
re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Rule for testing the library
test: $(NAME)
	$(CC) main.c -L. -lft -o $(OUTPUT)
	./$(OUTPUT)

