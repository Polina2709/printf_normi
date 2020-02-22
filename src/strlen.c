/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:06:43 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 12:59:36 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	strln(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	strln_x(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		return (i - 2);
	return (i);
}

int	strln_sps(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '-' || s[0] == '+' || s[0] == ' ')
		return (i - 1);
	return (i);
}

int	strln_s(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '-' || s[0] == '+')
		return (i - 1);
	return (i);
}

int	strlen_bytes(char *s, t_flag *flag)
{
	int i;
	int j;

	i = 0;
	if (flag->format[0] == 'c' && flag->flag_zero == 2)
		i = (int)sizeof(s) / 8;
	j = 0;
	while (s[j])
		j++;
	return (i + j);
}
