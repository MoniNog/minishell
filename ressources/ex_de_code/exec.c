#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "libft.h"    // votre libft avec ft_split, ft_strjoin, etc.

int execute_command(char *command, char **args, char **envp) {
	pid_t pid = fork();
	int status;

	if (pid < 0) {
		// Échec du fork
		perror("minishell");
		return (1); // code d’erreur arbitraire pour le shell
	}
	if (pid == 0) {
		// Processus enfant
		if (strchr(command, '/') != NULL) {
			// Chemin absolu ou relatif fourni
			execve(command, args, envp);
			// Si on arrive ici, erreur à l'execve
			if (errno == ENOENT) {
				fprintf(stderr, "%s: command not found\n", command);
				exit(127);
			} else if (errno == EACCES) {
				fprintf(stderr, "%s: permission denied\n", command);
				exit(126);
			} else {
				perror("minishell");
				exit(1);
			}
		} else {
			// Pas de slash -> recherche dans PATH
			char *path_env = getenv("PATH");
			char **paths = ft_split(path_env ? path_env : "", ':');
			char *fullpath = NULL;
			int i = 0;
			while (paths && paths[i]) {
				fullpath = ft_strjoin(paths[i], "/");
				char *tmp = fullpath;
				fullpath = ft_strjoin(fullpath, command);
				free(tmp);
				if (access(fullpath, X_OK) == 0) {
					execve(fullpath, args, envp);
					// Si execve échoue, on gère l'erreur et quitte
					if (errno == EACCES) {
						fprintf(stderr, "%s: permission denied\n", fullpath);
						exit(126);
					} else {
						perror("minishell");
						exit(1);
					}
				}
				free(fullpath);
				i++;
			}
			// Aucune occurrence trouvée dans PATH
			fprintf(stderr, "%s: command not found\n", command);
			exit(127);
		}
	}
	// Processus parent
	waitpid(pid, &status, 0);
	// Optionnel: on peut récupérer et traiter status ici
	return (0);
}
