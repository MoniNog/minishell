// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/10 10:35:45 by monoguei          #+#    #+#             */
// /*   Updated: 2025/03/17 14:23:14 by monoguei         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../../minishell.h"

// bool	ft_isalpha(int c)
// {
// 	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
// 		return (0);
// 	return (1);
// }

// // verifie si un entier est un caractere numerique
// int	ft_isdigit(int c)
// {
// 	if (!(c >= '0' && c <= '9'))
// 		return (0);
// 	return (1);
// }

// bool	ft_isalnum(int c)
// {
// 	if (!(ft_isdigit(c) || ft_isalpha(c)))
// 		return (0);
// 	return (1);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n == 0)
// 		return (0);
// 	while (i < n && s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	if (i < n && (s1[i] || s2[i]))
// 		return ((unsigned char)s1[i] - (unsigned char)s2[i]);

// 	return (0);
// }

// // copie colle avec malloc ET ajoute = a la fin
// char	*ft_strdup_equal(const char *src)
// {
// 	int		i;
// 	int		len;
// 	char	*dest;

// 	i = 0;
// 	len = ft_strlen(src);
// 	dest = (char *) malloc((len + 2) * sizeof(char));
// 	if (!dest)
// 		return (NULL);
// 	while (src[i] != 0)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '=';
// 	dest[i + 1] = 0;
// 	return (dest);
// }

// // Concatène str dest+src mod moni
// // return taille tot
// size_t	ft_strcat(char *dest, const char *src)
// {
// 	size_t	src_len;
// 	size_t	dest_len;
// 	size_t	i;
// 	size_t	size;

// 	src_len = ft_strlen(src);
// 	dest_len = ft_strlen(dest);
// 	size = src_len + dest_len;
// 	i = 0;
// 	if (size <= dest_len)
// 		return (src_len + size);
// 	while (src[i] != 0 && (dest_len + i) < (size - 1))
// 	{
// 		dest[dest_len + i] = src[i];
// 		i++;
// 	}
// 	if (size > 0)
// 		dest[dest_len + i] = 0;
// 	return (dest_len + src_len);
// }

// int	ft_strncmp_end(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n == 0)
// 		return (0);
// 	if (ft_strlen(s1) == n)
// 	{
// 		while (s1[i] && s2[i] && n > 1)
// 		{
// 			if (s1[i] != s2[i])
// 				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 			i++;
// 			n--;
// 		}
// 		return (0);
// 	}
// 	else
// 		return (-1);
// }

// // copie colle avec malloc
// char	*ft_strdup(const char *src)
// {
// 	int		i;
// 	int		len;
// 	char	*dest;

// 	i = 0;
// 	len = ft_strlen(src);
// 	dest = (char *) malloc((len + 1) * sizeof(char));
// 	if (!dest)
// 		return (NULL);
// 	while (src[i] != 0)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = 0;
// 	return (dest);
// }

// // compte nombre de caracteres d'une string
// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != 0)
// 		i++;
// 	return (i);
// }

// // t_list		*sort_list(t_list *lst){
// // 	t_list	tmp;
// // 	int		swap;
// // 	tmp = lst;
// // 	while (lst->next)
// // 	{
// // 		if (cmp_str(lst->data, lst->data->next) == 0)
// // 		{
// // 			swap = lst->data;
// // 			lst->data = lst->next->data;
// // 			lst->next->data = swap;
// // 			lst = tmp;
// // 		}
// // 		else
// // 			lst = lst->next;
// // 	}
// // 	lst = tmp;
// // }

// // return 0 si s2 doit être placé avant s1 dans la liste
// // return 1 si ordre ok
// int cmp_str(char* s1, char* s2) 
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (s1 && s2)
// 	{
// 		while (s1[i] && s2[j])
// 		{
// 			if(s1[i] > s2[j])
// 				return(0);
// 			if(s1[i] == s2[j])
// 				i++;
// 			j++;
// 		}
// 		return (1);
// 	}
// 	return (-1);
// }

// // void sort_copy_env_list(char **copy_env)
// // {
// // 	int i;
// // 	int j;
// // 	char *temp;
// // 	i = 0;
// // 	while (copy_env[i])
// // 	{
// // 		j = i + 1;
// // 		while (copy_env[j])
// // 		{
// // 			if (cmp_str(copy_env[i], copy_env[j]) == 0)
// // 			{
// // 				temp = copy_env[i];
// // 				copy_env[i] = copy_env[j];
// // 				copy_env[j] = temp;
// // 			}
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // }

// void	*copy_env_list(t_data *data)
// {
// 	char	*name;
// 	char	*value;
// 	int		i;
// 	int		size_env_list;

// 	size_env_list = 0;
// 	i = 0;

// 	t_env *temp = data->env;

// 	while (data->env)
// 	{
// 		size_env_list++;
// 		data->env = data->env->next;
// 	}

// 	data->env = temp;
// 	data->copy_env = malloc(sizeof(char **) * size_env_list + 1);
// 	if (!data->copy_env)
// 	{
// 		printf("error malloc");
// 		return (NULL);
// 	}
	
// 	while (data->env)
// 	{
// 		name = ft_strdup_equal(data->env->name);
// 		value = ft_strdup(data->env->value);
// 		ft_strcat(name, value);
// 		data->copy_env[i] = name;
// 		free(value);
// 		data->env = data->env->next;
// 		i++;
// 	}
// 	data->copy_env[i] = NULL;
// 	return (data->copy_env);
// }

// bool is_valid_env_var_syntax(char *s_env)
// {
// 	int		i;
// 	char	c;

// 	i = 0;
// 	if (s_env[i] == '_' || ft_isalpha(s_env[i]) == TRUE)
// 	{
// 		i++;
// 		while (s_env[i])
// 		{
// 			c = s_env[i];
// 			if (c == '_' || ft_isalnum(c) == TRUE)
// 				i++;
// 			else
// 				return (FALSE);
// 		}
// 		return (TRUE);
// 	}
// ft_putendl_fd("bash: export: 'X': not a valid identifier", 1);
// 	return (FALSE);
// }

// // [ok] fonction de comparaison s1, s2
// // [ok] cree une copie de la liste juste char *name=value donc liste chainee de char *
// // [ok] fonction syntaxe env var
// // [ ] fonction tri list_copie 
// // [ok] imprimer listechainee
// // [ ]	imprimer syntaxe execptions
// // // //	syntaxe 
// // // //		`declare -x VAR="value"` 
// // // //		si pas de value,	`declare -x VAR`
// // // //		si value vide,		`declare -x VAR=""`
// // [ ] free lst
// // 	// Nom de variable (name) : MY_VAR_1 (lettres, chiffres, underscore, ne commence pas par un chiffre)
// // 	// Valeur (value) : Hello_World123 (lettres, chiffres, underscores, espaces possibles)
// // 		if syntaxe invalide 
// // 			~`bash: export: 'X': not a valid identifier`
// // 			exit_status(1)
// // 	

// void 	print_copy_env(t_data *data)
// {
// 	int i;
// 	i = 0;
// 	while (data->copy_env[i])
// 	{
// 		ft_putstr_fd("declare -x ", 1);
// 		ft_putendl_fd(data->copy_env[i], 1);
// 		i++;
// 	}
// }

// bool	ft_isalpha(int c)
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
// 		{
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