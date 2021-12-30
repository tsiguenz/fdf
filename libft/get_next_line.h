/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:10:39 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/30 13:24:57 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 10

int		gnl_strlen(char *s);
char	*gnl_strdup(char *s);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
