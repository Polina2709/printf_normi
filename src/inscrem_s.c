/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscrem_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:53:10 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 12:57:14 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		part_2(char *tmp, int precis, int i)
{
	int flag;

	flag = 1;
	while (flag == 1)
	{
		if (tmp[i + precis] == '.')
			i--;
		if (tmp[i + precis] == '9')
		{
			tmp[i + precis] = '0';
			flag = 1;
		}
		else
		{
			tmp[i + precis]++;
			flag = 0;
		}
		i--;
	}
}

void			increm_s(char *tmp, int precis)
{
	int i;

	i = 0;
	while (tmp[i] != '.')
		i++;
	if (strln(tmp) == i)
		return ;
	if (tmp[i + precis + 1] >= '5')
	{
		if (tmp[i + precis] == '.')
			i--;
		if (tmp[i + precis] + 1 < '9')
			tmp[i + precis]++;
		else
			part_2(tmp, precis, i);
	}
}
