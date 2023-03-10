/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:56:27 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/03/10 19:54:05 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nline(char *box)
{
	int		len_bytes;
	char	*line;
	char	*temp;

	temp = ft_strchr(box, '\n');
	len_bytes  = 1 + (temp - box);
	

}

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
		if((bytes = read(fd, buffer, BUFFER_SIZE) > 0) //Optimizado ???
		{
			buffer[bytes]='\0';
			box = ft_strjoin(box,buffer):
		}
	}
	free(buffer);
	//Comprobar bytes
	return(box);
}
/*

[Description ft_read]
	1- Create a mallow
		{If doesn't}
			a- Return Null
	2- Iterate if bytes > 0 and the buffer are not an '\n'
		{If its}
		- Every run save in the variable the fd read count, and if
			> 0 close the buffer and add the content to the string box

*/

char	*get_next_line(int fd)
{
	static char	*box;
	char		*line;

	if (fd < 0)
		return (NULL);
	if(!box || (box && !ft_strchr(box,'\n')))
		box = ft_read(fd,box);
	if(!box)
		return (NULL);


}
/*
[Description get_next_line]
	1- Create (and check)the malloc with the BUFFER_SIZE
	BUFFER_SIZE



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