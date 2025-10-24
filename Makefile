# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: testing <testing@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 08:11:00 by testing           #+#    #+#              #
#    Updated: 2025/10/24 08:43:00 by testing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -g
NAME = test_libft

SRCS = ft_isalpha.c \
       ft_isdigitit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strlen.c \
       ft_strlcpy.c \
       ft_strlcat.c

TEST_SRC = test_libft.c

OBJS = $(SRCS:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(TEST_OBJ)
	@echo "Compilando tests..."
	@$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJ) -o $(NAME)
	@echo "✓ Compilación exitosa!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	@echo ""
	@./$(NAME)

# Comando especial: limpia, recompila y ejecuta tests
gotica: fclean
	@echo ""
	@echo "╔════════════════════════════════════════════╗"
	@echo "║         🚀 LIBFT - AUTO TEST 🚀           ║"
	@echo "╚════════════════════════════════════════════╝"
	@echo ""
	@echo "[1/3] Limpiando archivos antiguos..."
	@echo ""
	@echo "[2/3] Compilando proyecto..."
	@$(CC) $(CFLAGS) $(SRCS) $(TEST_SRC) -o $(NAME).exe
	@echo "✓ Compilación exitosa!"
	@echo ""
	@echo "[3/3] Ejecutando tests..."
	@echo ""
	@./$(NAME).exe

clean:
	@if exist *.o del /Q *.o 2>nul
	@echo "✓ Archivos objeto eliminados"

fclean: clean
	@if exist $(NAME) del /Q $(NAME) 2>nul
	@if exist $(NAME).exe del /Q $(NAME).exe 2>nul
	@echo "✓ Ejecutables eliminados"

re: fclean all

.PHONY: all clean fclean re test libft
