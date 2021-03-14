/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:38:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/13 23:49:30 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void start_parsing(char *line)
{
    char **sp_tab;
    int len;

    sp_tab = ft_split(line, '|');
    len = 0;
    while (sp_tab[len])
    {
        printf("%s\n", sp_tab[len]);
        len++;
    }
    printf("|%s| |%s|  |%d| |%s|\n", sp_tab[0], sp_tab[1], len, sp_tab[len]);
}