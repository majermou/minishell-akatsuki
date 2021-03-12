/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:05:05 by abdait-m          #+#    #+#             */
/*   Updated: 2021/03/12 22:37:22 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../srcs/get_next_line.h"

typedef struct      o_parse
{
    char *cmds;
    char **args;
    char *redirs;
}                   p_parse;

#endif