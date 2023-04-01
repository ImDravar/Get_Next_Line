/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:19:36 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/04/01 16:52:36 by rruiz-sa         ###   ########.fr       */
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (ft_free(&temp));
	while (s1[++i])
		temp[i] = s1[i];
	while (s2[j++])
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	free(s1);
	return (temp);
}

char	*ft_substr(char *box, unsigned int start, size_t max_len)
{
	size_t	len_str;
	char	*temp;
	size_t	i;

	i = 0;
	if (!box)
		return (0);
	len_str = ft_strlen(box);
	if (start > len_str)
	{
		temp = (char *)malloc(sizeof(char) * (1));
		if (!temp)
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (max_len > len_str - start)
		max_len = len_str - start;
	temp = (char *)malloc(sizeof(char) *(max_len + 1));
	if (!temp)
		return (NULL);
	while ((start < len_str) && (max_len > i) && (box[start]))
			temp[i++] = box[start];
	temp[i] = '\0';
	return (temp);
}

/*
[Description ft_strlen]
	1- Iterate the string, and return the counter(i)

[Description ft_strchr]
	1- Iterate the pointer of the string
	2- Every iteration check for matches with the character(c)
		- If it matches go out of the iteration
	3- Outside the iteration check for the match of (c) and the pointer of str
		- If it matches return the pointer
		- If not return (0)

[Description  ft_strjoin]
	1- Check if *s1  exist.
		{If doesn't}
		a- Create a simple (and check) malloc and give a 0 value
	3- Create the malloc with the size s1+s2(with +1 for the final \0)
		and check if it fails.
		{If fails}
			a- Free the temp and
	4- Copy the *s1 inside the *temp.
	5- Concat the *s2 inside the *temp.

Description ft_substr]
	0- Create a str temp container, len_str container and counter
	1- IF string is doesnt exist returns 0
	2- Get the len of the string
	3- If start is > to the len of str
		- Create a malloc, check if exist and return it
	4- If max_len > len of str minus start
		- Then max_len its equal to	the len of str minus start
	5- Create and check the malloc of the new str with the max_len
	6- Iterate while max_len its < len of str
		&& max_len > counter && box[start] exist
			- Put inside the temp the str
	7 - Close and return temp
	*/