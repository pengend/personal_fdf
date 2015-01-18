/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:33:54 by pxia              #+#    #+#             */
/*   Updated: 2014/11/10 18:13:19 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	l = ft_strlen(s);
	i = 0;
	str = (char*)malloc(sizeof(char) * (l + 1));
	while (i < l)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
