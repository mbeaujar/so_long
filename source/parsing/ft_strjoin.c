/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:24:48 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/12 20:25:52 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	big_strlen(char **str)
{
	int	i;

	i = 0;
	if (!str && !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void free_tab(char **str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	secure_free(char *str)
{
	if (str)
		free(str);
}

char	*ft_strjoin_endl(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		y;

	if (!s2)
		return (NULL);
	i = 0;
	tab = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 2));
	if (!tab)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2 && s2[y])
	{
		tab[i + y] = s2[y];
		y++;
	}
	tab[i + y] = '\n';
	tab[i + y + 1] = '\0';
	secure_free(s1);
	return (tab);
}
