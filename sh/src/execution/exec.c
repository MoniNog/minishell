/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:37:28 by lylrandr          #+#    #+#             */
/*   Updated: 2025/04/02 18:28:15 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	wait_all(void)
{
	int	status;

	while (wait(&status) > 0)
		;
}

int	has_next_cmd(t_input *node)
{
	while (node)
	{
		if (node->type == T_PIPE)
			return (1);
		node = node->next;
	}
	return (0);
}

t_input	*get_next_command(t_input *node)
{
	while (node && node->type != T_PIPE)
		node = node->next;
	if (node && node->type == T_PIPE)
		return (node->next);
	return (NULL);
}

void	exec_child(t_input *head, char *env_path, int in_fd, int out_fd)
{
	char	**cmd;
	char	*cmd_path;

	if (in_fd != 0)
	{
		dup2(in_fd, 0);
		close(in_fd);
	}
	if (out_fd != -1)
	{
		dup2(out_fd, 1);
		close(out_fd);
	}
	cmd = build_cmd_arg(head);
	cmd_path = get_path(env_path, cmd[0]);
	execve(cmd_path, cmd, NULL);
	printf("minishell: command not found: %s\n", cmd[0]);
}

int	exec_parent(int fd[2], int in_fd, int has_next)
{
	if (in_fd != 0)
		close(in_fd);
	if (has_next)
	{
		close(fd[1]);
		return (fd[0]);
	}
	else
		close(fd[0]);
	return (0);
}


void	exec_pipe(t_input *head, char *env_path)
{
	int		fd[2];
	int		out_fd;
	int		in_fd;
	pid_t	pid;

	in_fd = 0;
	while (head)
	{
		if (has_next_cmd(head))
			pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			if (has_next_cmd(head))
				out_fd = fd[1];
			else
				out_fd = -1;
			exec_child(head, env_path, in_fd, out_fd);
		}
		else
			in_fd = exec_parent(fd, in_fd, has_next_cmd(head));
		head = get_next_command(head);
	}
	wait_all();
}
