/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:05:14 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 13:07:17 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	chk_lng(t_flag *flag)
{
	int j;

	j = 0;
	while (flag->format_mod[j] != '\0')
	{
		if (flag->format_mod[j] == 'l')
		{
			if (flag->format_mod[j + 1] == 'l')
				return ('m');
			else
				return ('l');
		}
		if (flag->format_mod[j] == 'h')
		{
			if (flag->format_mod[j + 1] == 'h')
				return ('i');
			else
				return ('h');
		}
		if (flag->format_mod[j] == 'L')
			return ('L');
		j++;
	}
	return ('z');
}

char	*format_f(t_flag *flag, va_list ap)
{
	char *res;

	res = NULL;
	if (chk_lng(flag) == 'z' || chk_lng(flag) == 'l')
		res = ft_dtoa(va_arg(ap, double));
	else if (chk_lng(flag) == 'L')
		res = ft_ldtoa(va_arg(ap, long double));
	return (res);
}
