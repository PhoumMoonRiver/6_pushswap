/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:44:17 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 20:00:38 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		l;

	i = 0;
	new = NULL;
	if (!s)
	{
		free(s);
		return (NULL);
	}
	l = ft_strlen_end(s, '\0');
	if (l >= len)
		new = (char *)malloc(len + 1);
	else
		new = (char *)malloc(l + 1);
	if (!new)
		return (NULL);
	while (start < l && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen_end(s1, '\0') + \
				ft_strlen_end(s2, '\0') + 1));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

size_t	ft_strlen_end(const char *s, char end)
{
	size_t	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] != end)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	cat;

	cat = (char)(c);
	i = ft_strlen_end(s, '\0');
	j = -1;
	while (i != -1)
	{
		if (s[i] == cat)
		{
			j = i;
			return ((char *)&s[j]);
		}
		i--;
	}
	if (j == -1)
		return ((char *)0);
	return (NULL);
}
