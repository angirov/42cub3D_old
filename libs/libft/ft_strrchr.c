/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:32:34 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/13 22:20:14 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	rest;
	char	casted;

	casted = (char)c;
	rest = ft_strlen(str) + 1;
	str = str + ft_strlen(str);
	while (rest > 0 && *str != casted)
	{
		rest--;
		str--;
	}
	if (rest)
		return ((char *)str);
	return (NULL);
}

// // https://man7.org/linux/man-pages/man3/strchr.3.html
// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	*st = "Hello";
// 	int	ch = 'e'+ 256;

// 	printf("Find %c in %s: %s\n", ch, st, strrchr(st, ch));
// 	printf("Find %c in %s: %s\n", ch, st, ft_strrchr(st, ch));
// }
