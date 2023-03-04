/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:19:36 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/03/04 16:31:22 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			break ;
		str++;
	}
	if ((char)c == *str)
		return ((char *)str);
	return (0);
}
/*
[Description ft_strchr]
	1- Iterate the pointer of the string
	2- Every iteration check for matches with the character(c)
		- If it matches go out of the iteration
	3- Outside the iteration check for the match of (c) and the pointer of str
		- If it matches return the pointer
		- If not return (0)
*/