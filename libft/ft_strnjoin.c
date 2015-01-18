/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:40:05 by pxia              #+#    #+#             */
/*   Updated: 2014/11/11 13:14:40 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (str == NULL)
		return (str);
	return (ft_strncat(ft_strcpy(str, s1), s2, n));
}
