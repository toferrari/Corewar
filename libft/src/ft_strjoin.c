/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:56:01 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/31 12:12:44 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if ((s1 == NULL && s2 == NULL) || (s1 != NULL && s2 == NULL))
		return (NULL);
	result = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1 == NULL && s2 != NULL)
	{
		ft_strcpy(result, s2);
		return (result);
	}
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	return (ft_strcat(result, s2));
}
