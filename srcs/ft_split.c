/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:40:07 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/18 20:57:39 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static int			ft_count_words(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s && *s == c)
// 		s++;
// 	while (*s)
// 	{
// 		if ((*s == c && *(s + 1) != c) || *(s + 1) == '\0')
// 			count++;
// 		s++;
// 	}
// 	return (count);
// }

// static int			ft_len_words(char const *s, char c)
// {
// 	int	k;

// 	k = 0;
// 	while (s[k] && s[k] != c)
// 		k++;
// 	return (k);
// }

// static char			**ft_free(char **ptr, int size)
// {
// 	int i;

// 	i = 0;
// 	while (i++ < size)
// 		free(ptr[i]);
// 	free(ptr);
// 	ptr = NULL;
// 	return (NULL);
// }

// char				**ft_split(char const *s, char c)
// {
// 	char		**p;
// 	int			size;
// 	int			i;
// 	int			j;

// 	if (!s)
// 		return (NULL);
// 	size = ft_count_words(s, c);
// 	if (!(p = (char **)malloc(sizeof(char*) * (size + 1))))
// 		return (NULL);
// 	i = 0;
// 	while (i < size)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (!(p[i] = (char *)malloc(sizeof(char) * (ft_len_words(s, c) + 1))))
// 			return (ft_free(p, size));
// 		j = 0;
// 		while (*s && *s != c)
// 			p[i][j++] = *s++;
// 		p[i++][j] = '\0';
// 	}
// 	p[i] = NULL;
// 	return (p);
// }

// typedef struct 
// {
//     char **p;
//     int size;
//     int i;
//     int j;
//     int check_pp;
//     int check_p;
// } s_split;

static int			ft_count_words(char const *s, char c, s_split *sp)
{
	int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
        if ('"' == *s && sp->check_p % 2 == 0)
            sp->check_pp += 1;
        if ('\'' == *s && sp->check_pp % 2 == 0)
            sp->check_p += 1;
		if ((((*s == c && *(s + 1) != c) || *(s + 1) == '\0')) && sp->check_p % 2 == 0 && sp->check_pp % 2 == 0)
			count++;
		s++;
	}
    printf("how many words : %d\n", count);
	return (count);
}

static int			ft_len_words(char const *s, char c)
{
	int	k;

	k = 0;
	while (s[k] && s[k] != c)
		k++;
	return (k);
}

static char			**ft_free(char **ptr, int size)
{
	int i;

	i = 0;
	while (i++ < size)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char				**ft_split(s_split *sp, char const *s, char c)
{
	if (!s)
		return (NULL);
    sp->check_pp = 0;
    sp->check_p = 0;
	sp->size = ft_count_words(s, c, sp);
	if (!(sp->p = (char **)malloc(sizeof(char*) * (sp->size + 1))))
		return (NULL);
	sp->i = 0;
    sp->check_pp = 0;
    sp->check_p = 0;
	while (sp->i < sp->size)
	{
		while (*s && *s == c)
			s++;
		if (!(sp->p[sp->i] = (char *)malloc(sizeof(char) * (ft_len_words(s, c) + 1))))
			return (ft_free(sp->p, sp->size));
		sp->j = 0;
		while (*s)
        {
            if (*s == '\'' && sp->check_pp % 2 == 0)
                sp->check_p += 1;
            if (*s == '"' && sp->check_p % 2 == 0)
                sp->check_pp += 1;
            sp->p[sp->i][sp->j++] = *s++;
            if (*s == c && sp->check_pp % 2 == 0 && sp->check_p % 2 == 0)
                break;
        }
		sp->p[sp->i++][sp->j] = '\0';
	}
	sp->p[sp->i] = NULL;
	return (sp->p);
}
