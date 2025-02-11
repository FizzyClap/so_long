/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:15:53 by roespici          #+#    #+#             */
/*   Updated: 2024/06/06 08:45:03 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (ft_strlen(s) == 0)
	{
		if (c == '\0')
			return ((char *)s);
		return (NULL);
	}
	i = ft_strlen((char *)s) - 1;
	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
