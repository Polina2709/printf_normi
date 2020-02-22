/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_flags_with_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:14:51 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 12:15:28 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*work_with_u_part2(t_flag *flag, char *t)
{
	if (flag->precision > strln(t))
		t = ad_0_aftersign(t, flag->precision - strln(t));
	if (flag->width > strln(t) && flag->width > 1)
	{
		if (flag->flag_minus == 1)
			t = ad_fld_end(t, flag->width - strln(t));
		else
			t = ad_fld_strt(t, flag->width - strln(t));
	}
	return (t);
}

char			*work_flags_with_u(t_flag *flag, char *tmp)
{
	char *t;

	t = tmp;
	if (flag->precision == 0 && flag->prec == 0)
	{
		if (flag->flag_zero == 1 && flag->flag_minus == 0)
		{
			if (flag->width > strln(t))
				t = ad_0_aftersign(t, flag->width - strln(t));
		}
		else if (flag->width > strln(t))
		{
			if (flag->flag_minus == 1)
				t = ad_fld_end(t, flag->width - strln(t));
			else
				t = ad_fld_strt(t, flag->width - strln(t));
		}
		return (t);
	}
	else
		t = work_with_u_part2(flag, t);
	return (t);
}
