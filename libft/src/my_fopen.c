/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:41:22 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 10:36:21 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file g_stdin = {
	.fd = 0
};

t_file g_stdout = {
	.fd = 1
};

t_file g_stderr = {
	.fd = 2
};

t_file	*my_fopen(char *filename)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(*file));
	if (file == NULL)
		return (NULL);
	file->fd = open(filename, O_RDONLY);
	file->p = (unsigned char*)&file->buf[0];
	file->len = 0;
	return (file);
}
