#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct		s_cmd
{
	char			**args;
	int				is_pipe;
	int				fd[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;


int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(2, s, ft_strlen(s));
}

void	exit_fatal(void)
{
	ft_putstr("error fatal\n");
	exit(1);
}

char	*ft_strdup(char *s)
{
	int i = 0;
	char *res;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

void	clear(t_cmd *cmd)
{
	int i = 0;
	t_cmd	*tmp;

	while (cmd)
	{
		i = 0;
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}

t_cmd	*create_cmd(t_cmd *tmp, char **av, int av_num, int is_pipe)
{
	t_cmd	*new;
	int	i = 0;

	new = malloc(sizeof(t_cmd));
	new->args = malloc(sizeof(char *) * (av_num + 1));
	while (i < av_num)
	{
		new->args[i] = ft_strdup(av[i]);
		i++;
	}
	new->args[i] = NULL;
	new->is_pipe = is_pipe;
	new->next = NULL;
	new->prev = tmp;
	if (tmp)
		tmp->next = new;
	return (new);
}

int	ft_cd(t_cmd *cmd)
{
	int i = 0;
	int res = 0;

	while (cmd->args[i])
		i++;
	if (i != 2)
	{
		ft_putstr("error: cd: bad arguments\n");
		return (1);
	}
	if ((res = chdir(cmd->args[1])) < 0)
	{
		ft_putstr("error: cd: cannot change directory to ");
		ft_putstr(cmd->args[1]);
		ft_putstr("\n");
	}
	return (res);
}
