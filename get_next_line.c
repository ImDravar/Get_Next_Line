/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:56:27 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/04/06 13:35:17 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nline(char *box)
{
	int		len_bytes;
	char	*line;
	char	*temp;

	temp = ft_strchr(box, '\n');
	len_bytes = 1 + (temp - box);
	line = ft_substr(box, 0, len_bytes);
	if (!line)
		return (NULL);
	free(temp);
	return (line);
}

/*
[Description ft_nline]
	0- Create line and temp str containers, and bytes counter
	1- Put inside temp the box content up to the line separator
	2- Get the len bytes substracting th temp to the original plus one for the \0
	3- Get the line
	Create (and check)the malloc with the BUFFER_SIZE
	BUFFER_SIZE
*/

/*
[Description ft_free]
	1- Free the str memory
	2- Make Null the new value of str
	3- Return NULL
*/

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
			return (NULL);
		buffer[bytes] = '\0';
		mini_box = ft_strjoin(mini_box, buffer);
	}
	free(buffer);
	return (mini_box);
}

/*
[Description ft_read]
	1- Create a mallow
		{If doesn't}
			a- Return Null
	2- Iterate if bytes != 0 and the buffer are not an '\n'
		- Every run save in the variable the fd read count,
		   and check if the bytes readed > 0
			{If its}
				-Close the buffer and add the content to the string box
			{If doesn't}
				-Clean the strs memory
*/

char	*ft_cutword(char *prt)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (prt[i] != '\n' && prt[i])
		i++;
	if (!prt[i])
	{
		free(prt);
		return (NULL);
	}
	if (prt[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(prt) - i + 1));
	if (!dest)
		return (NULL);
	while (prt[i])
		dest[j++] = prt[i++];
	dest[j] = '\0';
	free(prt);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*box;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!box)
		box = ft_strdup("");
	box = ft_read(fd, box);
	if (!box)
	{
		free(box);
		return (NULL);
	}
	while (box[i] && box[i] != '\n')
		i++;
	line = ft_substr(box, 0, i + 1);
	box = ft_cutword(box);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);//Comprobar si hacer limpieza recursiva
	}
	return (line);
}
/*
[Description get_next_line]
	1- Create (and check)the malloc with the BUFFER_SIZE
	BUFFER_SIZE



*/
