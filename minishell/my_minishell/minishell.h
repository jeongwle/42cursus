/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:50:22 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/08 17:39:46 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ARROWUP 4283163
# define ARROWDOWN 4348699
# define BACKSPACE 127
#include "./libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <termios.h>
#include <termcap.h>

void	term_set(void);
void	delete_end(void);

#endif