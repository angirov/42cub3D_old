/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:04:38 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/20 23:37:47 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char const c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*new_str;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (ft_isset(set, *s1))
	{
		s1++;
		len--;
	}
	if (len == 0)
		return (ft_strdup(""));
	while (ft_isset(set, *(s1 + len - 1)))
		len--;
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[len] = '\0';
	while (len-- > 0)
		new_str[len] = s1[len];
	return (new_str);
}

// #include <stdio.h>
// int main()
// {
// 	char	*set = "12345";
// 	char	*s1 = "54321abcdefgh12345";

// 	printf("%s\n", ft_strtrim(s1, set));
// }
