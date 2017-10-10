/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:58:54 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/09 09:20:28 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_progsize(t_asm *env, int fd)
{
	t_arg			*lst;
	unsigned int	size;
	int				i;
	char			c;

	lst = env->args;
	size = 0;
	i = 3;
	while (lst)
	{
		if (lst->special & T_INSTRU)
			size += lst->tot_octets;
		lst = lst->next;
	}
	while (i > 0)
	{
		c = size / ft_power(256, i);
		size = size % ft_power(256, i);
		write(fd, &c, 1);
		i--;
	}
	c = size % ft_power(256, i);
	write(fd, &c, 1);
}

static void	write_comment(t_asm *env, int fd)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (env->comment[i])
		write(fd, &(env->comment[i++]), 1);
	c = '\0';
	while (i++ < COMMENT_LENGTH + 4)
		write(fd, &c, 1);
}

static void	write_header(t_asm *env, int fd)
{
	int				i;
	int				nb;
	unsigned char	c;

	i = 3;
	nb = COREWAR_EXEC_MAGIC;
	while (i > 0)
	{
		c = nb / ft_power(256, i);
		nb = nb % ft_power(256, i);
		write(fd, &c, 1);
		i--;
	}
	c = nb % ft_power(256, i);
	write(fd, &c, 1);
	i = 0;
	while (env->prog_name[i])
		write(fd, &(env->prog_name[i++]), 1);
	c = '\0';
	while (i++ < PROG_NAME_LENGTH + 4)
		write(fd, &c, 1);
	write_progsize(env, fd);
	write_comment(env, fd);
}

static void	write_core(t_asm *env, int fd)
{
	t_arg	*lst;
	int		line;

	lst = env->args;
	line = 0;
	while (lst)
	{
		if (lst->special & T_INSTRU)
		{
			write_inst(lst, fd);
			line++;
		}
		else if (lst->special & T_REG)
			write_reg(lst, fd);
		else if (lst->special & T_DIR)
			write_dir(lst, fd, line, env);
		else if (lst->special & T_IND)
			write_ind(lst, fd, line, env);
		lst = lst->next;
	}
}

char		*translate(t_asm *env, char *str)
{
	int		fd;
	char	*name;
	int		len;

	len = ft_strlen(str);
	name = ft_strnew(len + 2);
	name = ft_strncpy(name, str, len - 1);
	name = ft_strcat(name, "cor");
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write_header(env, fd);
	write_core(env, fd);
	close(fd);
	return (name);
}
