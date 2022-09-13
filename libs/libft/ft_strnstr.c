/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:53:24 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/08 20:29:31 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	while (ft_strlen(little) <= len--)
		if (!ft_strncmp(big++, little, ft_strlen(little)))
			return ((char *)big - 1);
	return (NULL);
}

// #include <bsd/string.h>
// int	main()
// {
// 	char	*big = "123456789";
// 	char	*little = "8";
// 	size_t	len = 8;

// 	printf(">>> Real function >>>\n");
// 	printf("RETURN %s\n", strnstr(big, little, len));

// 	printf(">>> Fake function >>>\n");
// 	printf("RETURN %s\n", ft_strnstr(big, little, len));
// }
