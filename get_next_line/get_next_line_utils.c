/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:23:55 by esteudle          #+#    #+#             */
/*   Updated: 2024/12/20 14:46:41 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_slen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_sjoin(char *s1, char *s2)
{
	char	*str12;
	char	*start;

	str12 = malloc (ft_slen(s1) + ft_slen(s2) + 1);
	if (!str12)
		return (NULL);
	start = str12;
	while (*s1)
	{
		*str12 = *s1;
		s1++;
		str12++;
	}
	while (*s2)
	{
		*str12 = *s2;
		s2++;
		str12++;
	}
	*str12 = '\0';
	return (start);
}

char	*ft_sdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(ft_slen(src) + 1);
	if (dest == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_callo(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_subs(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
