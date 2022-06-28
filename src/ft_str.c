/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:07 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 12:54:22 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s2 > *(unsigned char *)s1)
			return (-1);
		else if (*(unsigned char *)s1 == '\0' && *(unsigned char *)s2 == '\0')
			return (0);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strlen(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}
