/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:41:45 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/17 18:56:55 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stddef.h>
# include <stdbool.h>


typedef struct s_envp
{
	char	**envp;
}			t_envp;


// signals.c
__sighandler_t handler_sigint(void);
void init_signals(void);
void restore_terminal(void);

typedef enum s_token_type
{
	T_CMD,
	T_CMD_ARG,
	T_ARG,
	T_FILE,
	T_ENV,
	T_OP,
	T_PIPE,
	T_SQUOTE,
	T_DQUOTE
}			t_token_type;

typedef struct s_input
{
	char			*token;
	t_token_type	type;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	t_env		**env;// tableau envp
	t_input		**token;
	int			exit_status;
}				t_data;

// FONCTIONS LYLAH
// fonctions parsing
char	**fill_tab(char *input, char **array);
void	if_n_op(char *input, char **array, int *k, int *i);
void	if_operator(char *input, char **array, int *k, int i);
int		word_len(char *input);
char	**first_parsing(char *input);
char	**second_parsing(char **array);
void	first_word(char **input, char **env);
char	**parse_input(char *input);
char	**fill_second_tab(char **array, char **tab_token);
int		handle_non_operator(char **tab_token, char *array, int *index);
void	handle_operator(char **tab_token, char **array, int *index, int i);
void	if_quotes(char *input, char **array, int *k, int *i);
int		while_quotes(char *input, int i);
char	**malloc_second_parsing(int len);
int		is_open_quotes(char *input);

// fonctions token

int		is_cmd(char *token, char **env);
t_input	*tokenize(char **input);
t_token_type	get_token_type(t_input *token, char *input);
void	is_cmd_arg(t_input *token);

// fonctions path
char	**ft_split_path(char *fullpath);
char	*ft_find_executable(char **path, char *cmd);
char	*ft_get_path(char *fullpath, char *cmd);
char	*ft_get_env_path(char **env);

//fonctions main [ ] a renommer
void	print_token_type(t_input *token);
void	print_all_token_types(t_input *head);
void	print_tokens(char **tokens);

// FONCTIONS EXEC + MONI
// signals.c
__sighandler_t handler_sigint(void);
void	init_signals(void);
void	restore_terminal(void);

// utils.c
void	cleanup_memory(char *line, char **splited_line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// /builtin
void	b_echo(char **input);
void	b_pwd(void);
void	b_env(t_data *data);
void	b_cd(t_data *data, char *arg);

// init_environment
t_env	*create_env_var(char *env_var);
t_env	*convert_envp(char **envp);
void	init_env(t_data *data, char **envp);

// init_arg
void init_input(t_input *input);

// utils.c
int	ft_strncmp(const char *first, const char *second, size_t len);

#endif
