/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_flags_with_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:15:33 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 12:16:37 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*work_flags_with_x(t_flag *flag, char *tmp)
{
	tmp = first_step_for_x(flag, tmp);
	tmp = second_step_for_x(flag, tmp);
	return (tmp);
}

char	*first_step_for_x(t_flag *flag, char *tmp)
{
	char *s;

	if (flag->flag_hash == 1 && ft_strcmp(tmp, "0") == 0 && flag->prec == 0)
		return (tmp);
	if (flag->flag_hash == 1 && ft_strcmp(tmp, "") == 0 &&
			flag->prec == 1)
	{
		free(tmp);
		return (ft_strdup(""));
	}
	else if (flag->flag_hash == 1)
	{
		if (flag->format[0] == 'x')
			s = ft_strjoin("0x", tmp);
		else
			s = ft_strjoin("0X", tmp);
		free(tmp);
		return (s);
	}
	return (tmp);
}

char	*second_step_for_x(t_flag *flag, char *tmp)
{
	if (flag->precision == 0 && flag->prec == 0)
	{
		if (flag->flag_zero == 1 && flag->flag_minus == 0)
		{
			if (flag->width > strln(tmp))
				tmp = ad_0_after0x(tmp, flag->width - strln(tmp));
		}
		else if (flag->width > strln(tmp))
		{
			if (flag->flag_minus == 1)
				tmp = ad_fld_end(tmp, flag->width - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, flag->width - strln(tmp));
		}
	}
	else
		tmp = second_step_for_x2(flag, tmp);
	return (tmp);
}

char	*second_step_for_x2(t_flag *flag, char *tmp)
{
	if (flag->precision > strln_x(tmp))
		tmp = ad_0_after0x(tmp, flag->precision - strln_x(tmp));
	if (flag->width > strln(tmp) && flag->width > 1)
	{
		if (flag->flag_minus == 1)
			tmp = ad_fld_end(tmp, flag->width - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, flag->width - strln(tmp));
	}
	return (tmp);
}
