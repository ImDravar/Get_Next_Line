/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:06:23 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/04/08 16:33:26 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *mini_box, unsigned int start, size_t max_len)
{
	char	*temp;
	size_t	cont;
	size_t	len_str;

	cont = 0;
	if (!mini_box)
		return (0);
	len_str = ft_strlen(mini_box);
	if (max_len >= len_str - start && start < len_str)
		max_len = len_str - start;
	else if (start >= len_str)
		max_len = 0;
	else if (max_len > len_str)
		max_len = len_str;
	temp = malloc(sizeof(char) * (max_len + 1));
	if (!temp)
		return (0);
	while (cont < max_len)
		temp[cont++] = mini_box[start++];
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
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	temp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (ft_free(&s1));
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
	{
		free(s1);
		return (NULL);
	}
	while (s1[cont] != '\0')
	{
		temp[cont] = *((char *)(s1 + cont));
		cont++;
	}
	temp[cont] = '\0';
	return (temp);
}
/*
[Description ft_substr]
	0- Create a string temp container, len_str container and counter
	1- IF string  doesnt exist returns 0
	2- Get the len of the string
	3- If max_len >= len_str minus start &&  start is > to the len_str
		- Then max_len its equal to	the len_str minus start
	4- If start is >= to len_str
		- max_len = 0
	5- If max_len > to len_str
		- Then max_len its equal to the len_str
	6- Create and check the malloc of the temp str with the max_len
	7- Iterate while cont < max_len
		- Put inside the temp[cont] the str[start]
	8 - Close and return temp

[Description  ft_strjoin]
	1- Check if *s1  exist.
		{If doesn't}
			a- Create and close a  simple malloc
	2- Check if *s1 or *s2 exist
		{If doesn't}
			- Return 0
	3- Create the malloc with the size of the lens of s1+s2
		(with +1 for the final \0) and check if it fails.
		{If fails}
			a- Return 0
	4- Copy the *s1 inside the *temp.
	5- Copy the *s2 inside the *temp.
	6- Close temp and free the *s1
	7- Return temp

[Description ft_strchr]
	0- Check if str exist
		{If doesn't}
			- Return 0
	1- Check if the character its an \n
		{If its}
			-Return a string size of str+cont
	2- Iterate the pointer of the string while its not \0
	3- Every iteration check for matches with the character(c)
		- If it matches return a string size of str+cont
	4- Return 0

[Description ft_strlen]
	1- Check if the string have content
		{If doesn't}
			a- Return 0
	2- Iterate the string, and return the counter

[Description ft_strdup]
	0- Create a string temp container, len_str container and counter
	1- IF *s1 doesnt exist returns 0
	2- Get the len of *s1
	3- Create an check a  malloc with the size of len+1 (for \0)
	4-Iterate *1 while its not \0
		-Every iteration put in the temp string the value of the s1 cont
	5- Close temp and return it
*/