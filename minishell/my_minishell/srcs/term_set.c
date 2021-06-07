/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:44:11 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/07 15:59:10 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	store_present_term(t_mini *mini)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	mini->term_temp = term;
}

void	change_term(t_mini *mini)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &mini->term_temp);
}

void	term_set(void)
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
