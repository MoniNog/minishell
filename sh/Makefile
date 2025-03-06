NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lreadline -lncurses  # Ajout pour readline

SRC = src/main.c src/tokenize.c src/first_parsing.c src/second_parsing.c src/token_type.c src/get_path_file.c src/utils.c
OBJDIR = obj
OBJS = $(SRC:src/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Gestion de libft
LIBFT_PATH = ../lib
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $@ $(CFLAGS) -L$(LIBFT_PATH) -l:libft.a $(LDFLAGS)

$(LIBFT):
	@echo "Building libft ..."
	@$(MAKE) -s -C $(LIBFT_PATH)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)  # <-- Crée le sous-dossier si nécessairegi
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) -MMD -c $< -o $@


# S'assurer que obj/ existe
$(OBJDIR):
	@mkdir -p $(OBJDIR)

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@$(MAKE) clean -s -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@$(MAKE) fclean -s -C $(LIBFT_PATH)

re: fclean all

helgrind: $(NAME)
	valgrind --tool=helgrind ./$(NAME)

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME)
