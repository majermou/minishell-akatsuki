/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:38:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/18 00:05:12 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//  Try to make a function that calculates the number of parenthesis and check if it is an error or not,
// use open close method  : if " is open  then the next one should close it etcetera.....

// Try to use this split for your parsing :

// typedef struct 
// {
//     char **p;
//     int size;
//     int i;
//     int j;
//     int check_pp;
//     int check_p;
// } s_split;

// static int			ft_count_words(char const *s, char c, s_split *sp)
// {
// 	int	count;

// 	count = 0;
// 	while (*s && *s == c)
// 		s++;
// 	while (*s)
// 	{
//         if ('"' == *s && sp->check_p % 2 == 0)
//             sp->check_pp += 1;
//         if ('\'' == *s && sp->check_pp % 2 == 0)
//             sp->check_p += 1;
// 		if ((((*s == c && *(s + 1) != c) || *(s + 1) == '\0')) && sp->check_p % 2 == 0 && sp->check_pp % 2 == 0)
// 			count++;
// 		s++;
// 	}
//     printf("how many words : %d\n", count);
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

// char				**ft_split(s_split *sp, char const *s, char c)
// {
// 	if (!s)
// 		return (NULL);
//     sp->check_pp = 0;
//     sp->check_p = 0;
// 	sp->size = ft_count_words(s, c, sp);
// 	if (!(sp->p = (char **)malloc(sizeof(char*) * (sp->size + 1))))
// 		return (NULL);
// 	sp->i = 0;
//     sp->check_pp = 0;
//     sp->check_p = 0;
// 	while (sp->i < sp->size)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (!(sp->p[sp->i] = (char *)malloc(sizeof(char) * (ft_len_words(s, c) + 1))))
// 			return (ft_free(sp->p, sp->size));
// 		sp->j = 0;
// 		while (*s)
//         {
//             if (*s == '\'' && sp->check_pp % 2 == 0)
//                 sp->check_p += 1;
//             if (*s == '"' && sp->check_p % 2 == 0)
//                 sp->check_pp += 1;
//             sp->p[sp->i][sp->j++] = *s++;
//             if (*s == c && sp->check_pp % 2 == 0 && sp->check_p % 2 == 0)
//                 break;
//         }
// 		sp->p[sp->i++][sp->j] = '\0';
// 	}
// 	sp->p[sp->i] = NULL;
// 	return (sp->p);
// }


int count_char(char *line, char c)
{
    int i;
    int check_1;
    int check_2;
    int count;

    check_1 = 0;
    check_2 = 0;
    i = -1;
    count = 0;
    while (line[++i])
    {
        if (line[i] == '"')
            check_1 += 1;
        if (line[i] == '\'')
            check_2 += 1;
        if (line[i] == c && line[i + 1] != c && check_1 % 2 == 0 && check_2 % 2 == 0)
            count++;
    }
    return count;
}


void start_parsing(char *line, p_parse *prs)
{
    // int len;
    int i;

    prs->sc_cmds = ft_split(line, ';');
    i = 0;
    while (prs->sc_cmds[i])
    {
        printf("|%s|\n", prs->sc_cmds[i]);
        i++;
    }
}