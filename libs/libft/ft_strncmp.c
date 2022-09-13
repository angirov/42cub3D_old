/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:02:38 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/18 14:48:24 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1temp;

	s1temp = (unsigned char *)s1;
	if (n == 0)
		return (0);
	while (n > 1 && *s1temp && *s2 && *s1temp == *s2)
	{
		s1temp++;
		s2++;
		n--;
	}
	return (*s1temp - *s2);
}

// // https://man7.org/linux/man-pages/man3/strcmp.3.html
// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	*a1 = "à";
// 	char	*b1 = "abc";
// 	char	*a2 = "abc";
// 	char	*b2 = "abC";
// 	char	*a3 = "abc";
// 	char	*b3 = "abcd";
// 	int		num = 4;

// 	printf(">> Real function >>\n");
// 	printf("Compare %s vs. %s = %d\n", a1, b1, strncmp(a1, b1, num));
// 	printf("Compare %s vs. %s = %d\n", a2, b2, strncmp(a2, b2, num));
// 	printf("Compare %s vs. %s = %d\n", a3, b3, strncmp(a3, b3, num));

// 	printf(">> Fake function >>\n");
// 	printf("Compare %s vs. %s = %d\n", a1, b1, ft_strncmp(a1, b1, num));
// 	printf("Compare %s vs. %s = %d\n", a2, b2, ft_strncmp(a2, b2, num));
// 	printf("Compare %s vs. %s = %d\n", a3, b3, ft_strncmp(a3, b3, num));
// }
