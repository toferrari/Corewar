/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:54:47 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/14 16:51:10 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_struct(t_asm *env)
{
	int	i;

	env->str = NULL;
	env->args = NULL;
	i = -1;
	while (++i < REG_NUMBER)
		env->reg[i] = -1;
	ft_bzero(env->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(env->comment, COMMENT_LENGTH + 1);
}

static void	free_struct(t_asm *env)
{
	unsigned int	i;

	i = -1;
	if (env->str)
	{
		while (++i < env->nb_line)
		{
			free(env->str[i]);
			env->str[i] = NULL;
		}
		free(env->str);
		env->str = NULL;
	}
	free(env);
}

void		show_err2(int id, int line)
{
	if (id == 6)
	{
		ft_putstr_fd("Bad arguments: line ", 2);
		ft_putnbr_fd(line + 1, 2);
	}
	else if (id == 7)
		ft_putstr_fd("Void/Missing name or/and comment", 2);
	else if (id == 8)
	{
		ft_putstr_fd("Bad number of argument: line ", 2);
		ft_putnbr_fd(line + 1, 2);
	}
	ft_putendl_fd(".", 2);
	exit(EXIT_FAILURE);
}

void		show_err(int id, int line)
{
	if (id == 0)
		ft_putstr_fd("Malloc error", 2);
	else if (id == 1)
		ft_putstr_fd("Usage : ./asm [filename.s]", 2);
	else if (id == 2)
		ft_putstr_fd("File doesn't exist", 2);
	else if (id == 3)
	{
		ft_putstr_fd("Syntax error: line ", 2);
		ft_putnbr_fd(line + 1, 2);
	}
	else if (id == 4)
	{
		ft_putstr_fd("Label doesn't exist: line ", 2);
		ft_putnbr_fd(line + 1, 2);
	}
	else if (id == 5)
	{
		ft_putstr_fd("Instruction doesn't exist: line ", 2);
		ft_putnbr_fd(line + 1, 2);
	}
	ft_putendl_fd(".", 2);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_asm	*env;
	t_file	*file;
	char	*filename;

	if (ac != 2)
		show_err(1, 0);
	file = my_fopen(av[1]);
	if (file->fd == -1 || !ft_strstr(av[1], ".s"))
		show_err(2, 0);
	env = (t_asm*)malloc(sizeof(t_asm));
	if (env == NULL)
		exit(EXIT_FAILURE);
	init_struct(env);
	parsing_asm(env, file);
	filename = translate(env, av[1]);
	ft_printf("Writing output program to %s.\n", filename);
	free(filename);
	my_fclose(file);
	file = NULL;
	arg_delete(&env->args);
	free_struct(env);
	env = NULL;
	return (0);
}
