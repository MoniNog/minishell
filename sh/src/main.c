/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/02 13:20:14 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	cleanup_memory(char *line, char **splited_line)
{
	int	j;

	free(line);
	j = 0;
	while (splited_line[j])
	{
		free(splited_line[j]);
		j++;
	}
	free(splited_line);
}

void	kind_of_token(char *input)
{
	if (ft_strncmp_end((const char *)input, "echo", 4) == 0)
	{
		printf("\n%s = cmd\n", input);
		echo(input);
	}	
	else if (ft_strncmp_end((const char *)input, "cd", 2) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "pwd", 3) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "exit", 4) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "env", 3) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "export", 6) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "unset", 5) == 0)
		printf("\n%s = cmd\n", input);
	else
		printf("%s = arg\n\n", input);
}

void	display_input(char **splited_line)
{
	int	i;

	i = 0;
	while (splited_line[i])
	{
		printf("splited_line[%d]: %s\n", i, splited_line[i]);
		kind_of_token(splited_line[i]);
		sleep(1);
		i++;
	}
	printf("nombre de mots : %i\n", i);
}

char	**split_input(char *line)
{
	char	**splited_line;

	splited_line = ft_split(line, ' ');
	if (!splited_line)
	{
		fprintf(stderr, "Error splitting line\n");
		free(line);
		return (NULL);
	}
	return (splited_line);
}

char	*get_user_input(const char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		fprintf(stderr, "Error reading line\n");
		return (NULL);
	}
	printf("Input line: %s\n", line);
	return (line);
}


int	main(void)
{
	char	*input;
	char	**splited_input;

	while (1)
	{
		input = get_user_input("minishell> ");
		splited_input = split_input(input);
		if (ft_strncmp_end((const char *)input, "exit", 4) == 0)
			break ;
		display_input(splited_input);
		cleanup_memory(input, splited_input);
	}
	return (0);
}
