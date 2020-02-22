/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:40:01 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 12:52:11 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*insert_c_in_format_c(t_flag *flag, char chr, char *tmp)
{
	if (flag->flag_minus == 1)
		tmp = ad_fld_end_for_c(tmp, flag->width - 1, chr);
	else
		tmp = ad_fld_strt_for_c(tmp, flag->width - 1, chr);
	return (tmp);
}

char		*format_c(t_flag *flag, va_list ap)
{
	char *tmp;
	char chr;

	chr = (char)va_arg(ap, int);
	if (flag->width > 1)
		tmp = malloc(sizeof(char *) * (flag->width + 1));
	else
		tmp = malloc(sizeof(char *) * 2);
	if (flag->flag_zero == 1 && flag->flag_minus == 0)
	{
		if (flag->width > 1)
			tmp = ad_0_aftersps(tmp, flag->width);
	}
	else if (flag->width > 1)
		tmp = insert_c_in_format_c(flag, chr, tmp);
	if (flag->width < 2)
	{
		tmp[0] = chr;
		tmp[1] = 0;
	}
	if (chr == 0)
		flag->flag_zero = 2;
	return (tmp);
}

char		*ad_fld_strt_for_c(char *s, int nb_space, char chr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j != nb_space)
	{
		s[i] = ' ';
		i++;
		j++;
	}
	s[i] = chr;
	s[i + 1] = '\0';
	return (s);
}

char		*ad_fld_end_for_c(char *s, int nb_space, char chr)
{
	int j;

	j = 1;
	s[0] = chr;
	while (j != nb_space + 1)
	{
		s[j] = ' ';
		j++;
	}
	s[0] = chr;
	s[j] = '\0';
	return (s);
}
