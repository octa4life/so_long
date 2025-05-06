/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:15:18 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/06 09:49:09 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}
/*
int	main()
{
	printf("%d",ft_strlen("79ouieTest"));
}
*/
