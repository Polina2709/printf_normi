/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_fld_strt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:28:56 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 11:29:13 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ad_fld_strt(char *s, int nb_space)
{
	int		i;
	int		j;
	char	*new;
	char	*temp;

	i = 0;
	j = 0;
	new = NULL;
	if (!(temp = (char *)malloc(sizeof(char) * (nb_space + 1))))
		return (NULL);
	while (nb_space != 0)
	{
		temp[i] = ' ';
		i++;
		nb_space--;
	}
	temp[i] = 0;
	new = ft_strjoin(temp, s);
	ft_strdel(&temp);
	ft_strdel(&s);
	return (new);
}
