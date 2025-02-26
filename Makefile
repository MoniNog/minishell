# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 14:54:55 by lylrandr          #+#    #+#              #
#    Updated: 2025/02/26 15:13:56 by lylrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lreadline

SRC = $(wildcard src/*.c)
OBJDIR = obj
OBJS = $(SRC:src/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

# libft

LIBFT_PATH = ../lib./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C (LIBFT_PATH)
	@$(CC) $(OBJS) -o $@ $(CFLAGS) -L$(LIBFT_PATH) -llibft -o $(NAME)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

helgrind: $(NAME)
	valgrind --tool=helgrind ./$(NAME)

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME)
