/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/21 18:41:41 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	g_mini;

void	init_mini(t_mini *mini)
{
	mini->idx = 0;
	mini->pid = 0;
	mini->status = 0;
	mini->temp = NULL;
	mini->atoi_flag = 0;
	mini->make_history_flag = 0;
	store_present_term(mini);
	term_set();
	init_history_param(mini);
}

int		is_builtin(char **str)
{
	if (str)
	{
		if (!ft_strcmp("pwd", str[0]))
			return (1);
		else if (!ft_strcmp("cd", str[0]))
			return (1);
		else if (!ft_strcmp("export", str[0]))
			return (1);
		else if (!ft_strcmp("env", str[0]))
			return (1);
		else if (!ft_strcmp("unset", str[0]))
			return (1);
		else if (!ft_strcmp("exit", str[0]))
			return (1);
		else if (!ft_strcmp("echo", str[0]))
			return (1);
	}
	return (0);
}

void	free_split(char **split)
{
	int		i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	start_minishell(long long int compare)
{
	while (read(0, &compare, 4) > 0)
	{
		if (compare == '\t' || compare == ARROWLEFT || compare == ARROWRIGHT)
		{
			compare = 0;
			continue ;
		}
		else if (compare == '\n')
			change_term(&g_mini);
		else if (compare == 4)
		{
			if (!g_mini.curr->history || !*(g_mini.curr->history))
			{
				ft_putstr_fd("exit\n", 1);
				exit(0);
			}
			else
			{
				compare = 0;
				continue ;
			}
		}
		parse_by_input(&g_mini, &compare);
		term_set();
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	long long int	compare;

	argc = 0;
	g_mini.program_name = argv[0];
	argv = 0;
	compare = 0;
	init_mini(&g_mini);
	make_export_list(&g_mini, envp);
	signal(SIGINT, (void *)signal_handler);
	signal(SIGQUIT, (void *)signal_handler);
	write(1, "minishell > ", 12);
	start_minishell(compare);
}
