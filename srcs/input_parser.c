/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:38:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/17 15:39:48 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


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