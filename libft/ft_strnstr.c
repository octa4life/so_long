/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:30:37 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/29 13:49:24 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (s2_len == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && i + s2_len <= len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && j < s2_len)
			j++;
		if (j == s2_len)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	s1[] = "Hello World";
	char	*result;

	result = ft_strnstr(s1, "World", 13);
	printf("Testing ft_strnstr: s%n",result);
}
*/
