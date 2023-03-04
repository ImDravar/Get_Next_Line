/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:56:27 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/03/04 17:29:13 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *box)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = mmalloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buffer)
		return (NULL); // Limpiar buffer ?
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		

	}
}

char	*get_next_line(int fd)
{
	static char	*box;
	char		*line;

	if (fd < 0)
		return (NULL);
}
/*
[Description get_next_line]
	1- Create (and check)the malloc with the BUFFER_SIZE
	BUFFER_SIZE


[Description ft_read]
	1- Create a mallow
			{If doesn't}
				a- Return Null

*/
/*
1- Check If the number passed by parameter exist
   {If doesn't}
     a- Call [ft_printf_s] ans send "0x0"
     b- Check if the return of the [ft_printf_s] its incorrect,if its, return -1
   {If exist}
     A- Call [ft_printf_s] ans send "0x"
     B- Check if the return of the [ft_printf_s] its incorrect,if its, return -1
     C- Call [ft_printf_p_num] ans send the number and the hex base


*/