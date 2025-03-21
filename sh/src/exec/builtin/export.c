/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:35:45 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/21 20:42:12 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

// copie colle avec malloc ET ajoute = a la fin
char	*ft_strdup_equal(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *) malloc((len + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '=';
	dest[i + 1] = 0;
	return (dest);
}

// Concatène str dest+src mod moni
// return taille tot
size_t	ft_strcat(char *dest, const char *src)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	size;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	size = src_len + dest_len;
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != 0 && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (size > 0)
		dest[dest_len + i] = 0;
	return (dest_len + src_len);
}

int	ft_strncmp_end(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == n)
	{
		while (s1[i] && s2[i] && n > 1)
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
			n--;
		}
		return (0);
	}
	else
		return (-1);
}

void	*copy_env_list(t_data *data)
{
	char	*name;
	char	*value;
	int		i;
	int		size_env_list;

	size_env_list = 0;
	i = 0;

	t_env *temp = data->env;

	while (data->env)
	{
		size_env_list++;
		data->env = data->env->next;
	}

	data->env = temp;
	data->copy_env = malloc(sizeof(char **) * size_env_list + 1);
	if (!data->copy_env)
	{
		printf("error malloc");
		return (NULL);
	}
	
	while (data->env)
	{
		name = ft_strdup_equal(data->env->name);
		value = ft_strdup(data->env->value);
		ft_strcat(name, value);
		data->copy_env[i] = name;
		free(value);
		data->env = data->env->next;
		i++;
	}
	data->copy_env[i] = NULL;
	return (data->copy_env);
}

bool is_valid_env_var_syntax(char *s_env)
{
	int		i;
	char	c;

	i = 0;
	if (s_env[i] == '_' || ft_isalpha(s_env[i]) == TRUE)
	{
		i++;
		while (s_env[i])
		{
			c = s_env[i];
			if (c == '_' || ft_isalnum(c) == TRUE)
				i++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	// ft_putendl_fd("bash: export: '		[ ] a completer
	// 	X
	// 	': not a valid identifier", 1);
	return (FALSE);
}

// ret 1 = swap nec
// ret 0 = PAS de swap
int	compare_words(char *w1, char *w2)
{
	int i = 0;

	while (w1[i] && w2[i])
	{
		if (w1[i] < w2[i])
			return 0;// 
		if (w1[i] > w2[i])
			return 1;// b > a SWAP
		if  (w1[i] == w2[i])
			i++;
	}
    if (w1[i])
		return 1;
	else
		return 0;
}

void	sort_words(char	**words, int len)
{
	int	i = 0;
	int	j = 1;
	int c = 0;


	while(i < len && j < len)
	{
		if (compare_words(words[i], words[j]) == 1)
			swap_words(&words[i], &words[j]);
		else
			j++;
		if (j == len)
		{
			i++;
			j = i + 1;
		}
	}
}

void 	print_copy_env(t_data *data)
{
	int i;
	i = 0;
	while (data->copy_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(data->copy_env[i], 1);
		i++;
	}
}

// [ok] fonction de comparaison s1, s2
// [ok] cree une copie de la liste juste char *name=value donc liste chainee de char *
// [ok] fonction syntaxe env var
// [ ] fonction tri list_copie 
// [ok] imprimer char *
// [ ]	imprimer syntaxe execptions
// // //	syntaxe 
// // //		`declare -x VAR="value"` 
// // //		si pas de value,	`declare -x VAR`
// // //		si value vide,		`declare -x VAR=""`
// [ ] free lst
// 	// Nom de variable (name) : MY_VAR_1 (lettres, chiffres, underscore, ne commence pas par un chiffre)
// 	// Valeur (value) : Hello_World123 (lettres, chiffres, underscores, espaces possibles)
// 		if syntaxe invalide 
// 			~`bash: export: 'X': not a valid identifier`
// 			exit_status(1)
// 	

/// @brief built-in `export` `export VAR=value` `export VAR` `export VAR+=value`
/// @param data 
void	b_export(t_data *data)
{
	return ;
}

// void	b_export(t_data *data)
// {
// 	t_env	*current;
// 	data->env = current;
// 	if (data->input->T_CMD)
// 	{
// 		copy_env_list(data->env);
// 		print_copy_env(data->copy_env);
// 	}
// 		//parcourir env, afficher dans ordre alphabetique dans le terminal
// //		syntaxe 
// //			`declare -x VAR="value"` 
// //			si pas de value,	`declare -x VAR`
// //			si value vide,		`declare -x VAR=""`
// 	}
// 	else
// 	control syntaxe
// {
// 		if ('=' present)
// 		{`````
// 			si existe deja 
// 				maj value
// 			else 
// 				ajoute VAR=value a env
// 		}
// 		else
// 		{
// 			si existe deja
// 				rien
// 			else
// 				creation valeur 
// 	}
// 	si succes exit_status 0
// }
