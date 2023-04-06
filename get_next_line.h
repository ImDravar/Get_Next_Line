/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:59:22 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/04/06 14:43:59 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>
/*
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
*/

char	*get_next_line(int fd);
char	*ft_nline(char *box);
char	*ft_read(int fd, char *mini_box);
char	*get_next_line(int fd);
char	*ft_free(char **mini_box);

// UTILS //
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *mini_box, unsigned int start, size_t max_len);
char	*ft_strdup(char *s1);

#endif
