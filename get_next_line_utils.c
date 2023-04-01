/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:06:23 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/04/01 19:15:01 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*temp;
	size_t	cont;
	size_t	len_s;

	cont = 0;
	if (!str)
		return (0);
	len_s = ft_strlen(str);
	if (len >= len_s - start && start < len_s)
		len = len_s - start;
	else if (start >= len_s)
		len = 0;
	else if (len > len_s)
		len = len_s;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (cont < len)
		temp[cont++] = str[start++];
	temp[cont] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		cont;
	int		cont_temp;

	cont = -1;
	cont_temp = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	temp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (0);
	while (s1[++cont])
		temp[cont] = s1[cont];
	while (s2[cont_temp])
		temp[cont++] = s2[cont_temp++];
	temp[cont] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strchr(char *str, int c)
{
	int	cont;

	cont = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)(str + cont));
	while (str[cont] != '\0')
	{
		if (str[cont] == (char)c)
			return ((char *)(str + cont));
		cont++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	cont;

	cont = 0;
	if (!str)
		return (0);
	while (str[cont])
		cont++;
	return (cont);
}

char	*ft_strdup(char *s1)
{
	int		cont;
	char	*temp;
	int		len;

	cont = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (s1[cont] != '\0')
	{
		temp[cont] = *((char *)(s1 + cont));
		cont++;
	}
	temp[cont] = '\0';
	return (temp);
}
