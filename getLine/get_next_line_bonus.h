/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majermou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:18:02 by majermou          #+#    #+#             */
/*   Updated: 2019/12/31 16:16:44 by majermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define FD 10000

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
int			check_break_line(char *tab);
int			ft_strlen(const char *str);
int			check_previous_read(char **line, char *tab);
char		*ft_strjoin(char *line, char *tab);
int			dealocate(char **line, char **tab, int ret, int var_bol);
int			error_check(int fd, char **line, char **tab);
void		for_next_read(char **tab);

#endif
