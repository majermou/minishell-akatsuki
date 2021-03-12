/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:38:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/12 16:27:30 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../getLine/get_next_line.h"

typedef struct      o_parse
{
    char *cmds;
    char **args;
    char *redirs;
}                   p_parse;


void  minishell()
{
    char *tab;
    char tmp[100];
    int ret;
    
    tab = NULL;
    write(1, "mini$hell~~> ", 13);
    while((ret = get_next_line(0, &tab)) > 0)
    {
        write(1, "mini$hell~~> ", 13);
    }
    printf("%s", tab);
}


int main()
{
    
    minishell();
    return 0;
}