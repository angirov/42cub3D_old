/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:48:09 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/12 22:51:57 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*newstr;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f((unsigned int)i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
