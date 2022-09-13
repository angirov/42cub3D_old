/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:50:15 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/10 16:50:45 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	i = 0;
	dup = (char *)malloc(size);
	if (dup == NULL)
		return (NULL);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char	*str = "123456";

// 	printf("%s\n", ft_strdup(str));
// 	printf("%s\n", strdup(str));
// }
