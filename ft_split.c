/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:04:21 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:34:12 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	fill(char *s, char c, char **array, int count)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (k < count)
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				array[k][j] = s[i];
				i++;
				j++;
			}
			array[k][j] = '\0';
			k++;
		}
	}
}

static char	**allocate_matrix(char *s, char c, char **array)
{
	int	i[2];
	int	count;

	i[0] = 0;
	i[1] = 0;
	count = 0;
	while (s[i[0]])
	{
		if (s[i[0]] != c)
		{
			while (s[i[0]] && s[i[0]] != c)
			{
				count++;
				i[0]++;
			}
			array[i[1]] = (char *)malloc(sizeof(char) * (count + 1));
			if (array[i[1]] == NULL)
				return (NULL);
			count = 0;
			i[1]++;
		}
		if (s[i[0]] != '\0')
			i[0]++;
	}
	return (array);
}

static	char	**all_free(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char *s, char c, int *word)
{
	char	**array;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_word(s, c);
	*word = (count + 1);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	if (allocate_matrix(s, c, array) == NULL)
	{
		all_free(array);
		return (NULL);
	}
	fill(s, c, array, count);
	array[count] = NULL;
	return (array);
}
