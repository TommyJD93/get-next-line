/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:45:05 by tterribi          #+#    #+#             */
/*   Updated: 2022/01/20 21:42:31 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	while (*str != '\0')
	{
		if (*str == c)
			last = str;
		str++;
	}
	return ((char *)last);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}