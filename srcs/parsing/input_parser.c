/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:38:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/11 17:07:23 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      o_parse
{
    char *cmds;
    char **args;
    char *redirs;
}                   p_parse;


void  minishell()
{
    char tmp[100]; 
    
    while(1)
    {
        printf("mini$hell~~> ");
    }
}


int main()
{
    
    minishell();
    return 0;
}