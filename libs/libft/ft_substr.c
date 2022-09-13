/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:56:29 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/02 22:09:18 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	int		sub_size;

	if (!s)
		return (0);
	sub_size = (int)ft_strlen(s) - start + 1;
	if (sub_size < 0)
		return (ft_strdup(""));
	else if (sub_size > (int)len + 1)
		sub_size = len + 1;
	else
		len = sub_size - 1;
	sub_str = (char *)malloc(sub_size * sizeof(char));
	if (!sub_str)
		return (sub_str);
	while (sub_size-- > 1)
		*sub_str++ = *(s + start++);
	*sub_str = '\0';
	return (sub_str - len);
}

// // an empty string (len = 0) is different from a null string
// #include <stdio.h>
// int	main(void)
// {
// 	char			*string = "Helloworld";
// 	char			*substring;
// 	unsigned int	start =	17; // check a too high index too!
// 	size_t			len =	0;  // check 0 lenn too!

// 	substring = ft_substr(string, start, len);
// 	printf("Substring = %s\n", substring);

// 	// free(substring);
// 	return (0);
// }
