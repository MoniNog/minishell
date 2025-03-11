/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:41:45 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/10 12:29:14 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"
# include <signal.h>     // signal, SIGINT, SIGQUIT, SIG_IGN
# include <termios.h>    // termios, tcgetattr, tcsetattr
# include <unistd.h>     // STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, write
# include <sys/wait.h>   // waitpid, WIFSIGNALED, WTERMSIG
# include <stddef.h>
# include <stdbool.h>


typedef enum
{
	CMD,
	ARG,
	FILE_TYPE,
	ENV
} WordType;

typedef struct s_token
{
	char 		*value;
	WordType	type;
} 				t_token;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_input
{
	char	*CMD;
	char	*ARG;
}	t_input;

typedef struct s_data
{
	t_input		**input;// ligne de commande
	t_env		**env;// tableau envp
	int			exit_status;
}				t_data;
// signals.c
__sighandler_t handler_sigint(void);
void init_signals(void);
void restore_terminal(void);

// fonctions parsing
char	**fill_tab(char *input, char **array);
void	if_n_op(char *input, char **array, int *k, int *i);
void	if_operator(char *input, char **array, int *k, int i);
int		word_len(char *input);
char	**first_parsing(char *input);
char	**second_parsing(char **array);
//void	*read_input(char **input, char **env);
void	first_word(char **input, char **env);
char	**parse_input(char *input);
char	**fill_second_tab(char **array, char **tab_token);
int		handle_non_operator(char **tab_token, char *array, int *index);
void	handle_operator(char **tab_token, char **array, int *index, int i);


// fonctions token

int		is_cmd(char *token, char **env);
//void	env_token(char *token);
//void	operator_token(char *token);
//void	word_token(char *token);

// fonctions path

char	**ft_split_path(char *fullpath);
char	*ft_find_executable(char **path, char *cmd);
char	*ft_get_path(char *fullpath, char *cmd);
char	*ft_get_env_path(char **env);


void	cleanup_memory(char *line, char **splited_line);

// fonctions utils

int	ft_strncmp(const char *s1, const char *s2, size_t n);

//MAIN
// void	display_input(char **splited_line);

// Builtin
void	b_echo(char **input);
void	b_pwd(void);
void	b_env(t_data *data);
void	b_cd(t_data *data, char *arg);

// init_environment
t_env *create_env_var(char *env_var);
t_env *convert_envp(char **envp);
void init_env(t_data *data, char **envp);

#endif