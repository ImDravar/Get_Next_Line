/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:56:27 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/04/08 13:22:07 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *mini_box)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes != 0 && !ft_strchr(mini_box, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(mini_box);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		mini_box = ft_strjoin(mini_box, buffer);
	}
	free(buffer);
	return (mini_box);
}


char	*ft_cut(char *mini_box)
{
	int		cont_a;
	int		cont_b;
	char	*temp;

	cont_a = 0;
	cont_b = 0;
	while (mini_box[cont_a] && mini_box[cont_a] != '\n')
		cont_a++;
	if (!mini_box[cont_a])
	{
		free(mini_box);
		return (NULL);
	}
	if (mini_box[cont_a] == '\n')
		cont_a++;
	temp = malloc(sizeof(char) * (ft_strlen(mini_box) - cont_a + 1));
	if (!temp)
		return (NULL);
	while (mini_box[cont_a])
		temp[cont_b++] = mini_box[cont_a++];
	temp[cont_b] = '\0';
	free(mini_box);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*box;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	box = ft_read(fd, box);
	if (!box)
		return (NULL);
	while (box[i] && box[i] != '\n')
		i++;
	line = ft_substr(box, 0, i + 1);
	box = ft_cut(box);
	if (!line[0])
	{
		free(line);
		free(box);
		return (NULL);
	}
	return (line);
}

/*
[Description get_next_line]
	1-Check if the fd or the BUFFER_SIZE are <0
		{If its}
			a-Return NULL
	2-Read the fd and put inside of the string static
	3-Check if the static exist
	4-Iterate while container have content and its not a \n
	5-With the firts \n detection, put the rest inside a temp string
	6-Cut the line from the static and put inside again
	7- Check if line[0] exist
		{If doesn't}
			a-Free line and static
	8- Return line

[Description ft_read]
	1- Create a mallow and check if its exist
		{If doesn't}
			a- Return Null
	2- Iterate if bytes != 0 and the buffer are not an '\n'
		- Every run save in the variable the fd read count,
		   and check if the bytes readed > 0
			{If its}
				-Close the buffer and add the content to the string box
			{If doesn't}
				-Clean the strs memory

[Description ft_cut]
	1-Iterate while str exist and its not a \n
		-Save counter (this save where is the \n)
	2-Check if Str[cont] stills exist
		{If doesn't}
			a- free str and return NULL
	3-Check if Str[cont] its equalt to \n
		{If its}
			a- iterate cont
	4- Create and check malloc size of len_str - cont(+1 for \0)
	5-Iterate while str[cont] exist and put the content in a temp str
	6- Out of the iteration close the temp
	7- Free the str and return temp


[Description get_next_line]
	1- Create (and check)the malloc with the BUFFER_SIZE
	BUFFER_SIZE



*/
