/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:05:06 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/05 14:17:36 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *str, char *cmp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	*str = "ui tond  ";
	char		c;
	char		*res;

	c = 't';
	res = ft_strchr(str, c);
	if (res != NULL)
	{
		printf(" le caractere '%c'est dans la chaine '%s\n'", c, res);
	}
	else
	{
		printf("le caractere '%c' n'est pas dans la chaine de caractere \n", c);
	}
	return (0);
}
*/
