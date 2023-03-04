/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:56:27 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/03/04 16:53:29 by rruiz-sa         ###   ########.fr       */
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
		return (NULL);
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
	1- Check If the fd have content
		{If doesn't}
			a- Return Null


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