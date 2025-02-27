#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"

typedef enum
{
	CMD,
	ARG,
	FILE_TYPE,
	ENV
} WordType;

typedef struct s_token
{
	char *value;
	WordType type;
} t_token;

// fonctions parsing

char	**fill_tab(char *input, char **array);
void	if_n_op(char *input, char **array, int *k, int *i);
void	if_operator(char *input, char **array, int *k, int i);
int		word_len(char *input);
char	**first_parsing(char *input);
char	**second_parsing(char **array);
void	*read_input(char *input, char **env);
void	first_word(char **input, char **env);
char	**parse_input(char *input);
char	**fill_second_tab(char **array, char **tab_token);
int		handle_non_operator(char **tab_token, char *array, int *index);
void	handle_operator(char **tab_token, char **array, int *index, int i);


// fonctions token

int		is_cmd(char *token, char **env);
void	env_token(char *token);
void	operator_token(char *token);
void	word_token(char *token);

#endif

//struct def s_token
//{
//	int		tok;

//}		t_token;
