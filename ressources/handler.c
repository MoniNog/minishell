#include <stdio.h>      // printf
#include <stdlib.h>     // free, exit
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>     // signal, SIGINT, SIGQUIT, SIG_IGN
#include <termios.h>    // termios, tcgetattr, tcsetattr
#include <unistd.h>     // STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, write
#include <sys/wait.h>   // waitpid, WIFSIGNALED, WTERMSIG

// Handler pour SIGINT (Ctrl+C)
void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	// Optionnel: mettre à jour un statut global pour $? à 130
}

// Initialisation des handlers de signaux pour le shell parent
void    init_signals(void)
{
	// Ignorer Ctrl-\ (SIGQUIT) pour ne pas quitter le shell
	signal(SIGQUIT, SIG_IGN);
	// Intercepter Ctrl-C (SIGINT) avec notre handler
	signal(SIGINT, handle_sigint);

	// Désactiver l'écho des ^C/^\
	struct termios term;
	if (tcgetattr(STDIN_FILENO, &term) == 0)
	{
		term.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
}

int main(void)
{
	char *input;
	int  exit_status = 0;

	init_signals();
	while (1)
	{
		input = readline("minishell> ");
		if (!input) {                   // Ctrl+D (EOF) détecté
			write(STDOUT_FILENO, "exit\n", 5);
			break;                      // sortir de la boucle -> fin du shell
		}
		if (*input != '\0')
			add_history(input);
		// Ici, on traiterait la commande (parsing + execution).
		// ... (code d'exécution non montré)
		free(input);
	}
	// Optionnel: nettoyer l'historique readline si besoin, etc.
	return exit_status;
}
