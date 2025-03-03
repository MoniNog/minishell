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


// typedef struct s_path
// {
// 	char	
// }
void	echo(char *input);

// signals.c
__sighandler_t handler_sigint(void);
void init_signals(void);
void restore_terminal(void);

#endif

//struct def s_token
//{
//	int		tok;

//}		t_token;
