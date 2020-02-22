/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_flags_with_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:12:58 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 13:01:14 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*work_flags_with_p(t_flag *flag, char *tmp)
{
	if (flag->width > strln(tmp) && flag->precision < flag->width)
	{
		if (flag->flag_minus == 1)
			tmp = ad_fld_end(tmp, flag->width - strln(tmp));
		else if (flag->flag_zero == 1 && flag->flag_minus == 0)
			tmp = ad_0_after0x(tmp, flag->width - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, flag->width - strln(tmp));
	}
	if ((ft_strequ(tmp, "0x0") == 1 && flag->prec == 1))
	{
		if (flag->precision == 0)
		{
			free(tmp);
			return (ft_strdup("0x"));
		}
		else if (flag->precision > 1)
			tmp = ad_0_after0x(tmp, flag->precision - 1);
	}
	if (flag->prec == 1 && flag->precision > strln_x(tmp))
		tmp = ad_0_after0x(tmp, flag->precision - strln_x(tmp));
	return (tmp);
}
