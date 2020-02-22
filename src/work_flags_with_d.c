/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_flags_with_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:08:18 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 13:03:33 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*work_flags_with_d(t_flag *flag, char *tmp)
{
	if (ft_strcmp("0", tmp) == 0 && flag->precision == 0
			&& flag->prec == 1)
		return (check_zero_for_d(flag, tmp));
	tmp = first_step_for_d(flag, tmp);
	tmp = second_step_for_d(flag, tmp);
	return (tmp);
}

char	*check_zero_for_d(t_flag *flag, char *tmp)
{
	if (flag->width < 2)
	{
		if (flag->flag_plus == 1)
		{
			ft_strdel(&tmp);
			tmp = ft_strjoin(tmp, "+");
		}
		else
		{
			ft_strdel(&tmp);
			tmp = ft_strjoin(tmp, "\0");
		}
	}
	else
	{
		ft_strdel(&tmp);
		tmp = ft_memset(ft_memalloc(flag->width + 1), ' ', flag->width + 1);
		if (flag->flag_plus == 1 && flag->flag_minus == 0)
			tmp[flag->width - 1] = '+';
		else if (flag->flag_plus == 1 && flag->flag_minus == 1)
			tmp[0] = '+';
	}
	tmp[flag->width] = '\0';
	return (tmp);
}

char	*first_step_for_d(t_flag *flag, char *tmp)
{
	char *ptr;

	if (flag->flag_plus == 1)
	{
		if (tmp[0] != '-')
		{
			ptr = ft_strjoin("+", tmp);
			ft_strdel(&tmp);
			return (ptr);
		}
	}
	else if (flag->flag_space == 1)
	{
		if (tmp[0] != '-')
		{
			ptr = ft_strjoin(" ", tmp);
			ft_strdel(&tmp);
			return (ptr);
		}
	}
	return (tmp);
}

char	*second_step_for_d(t_flag *flag, char *tmp)
{
	int len;

	len = strln(tmp);
	if (flag->precision == 0 && flag->prec == 0)
	{
		if (flag->flag_zero == 1 && flag->flag_minus == 0)
		{
			if (flag->width > len)
				tmp = ad_0_aftersps(tmp, flag->width - len);
		}
		else if (flag->width > len)
		{
			if (flag->flag_minus == 1)
				tmp = ad_fld_end(tmp, flag->width - len);
			else
				tmp = ad_fld_strt(tmp, flag->width - len);
		}
	}
	else
		tmp = second_step_for_d2(flag, tmp);
	return (tmp);
}

char	*second_step_for_d2(t_flag *flag, char *tmp)
{
	int lensps;

	lensps = strln_sps(tmp);
	if (flag->precision > lensps && flag->flag_minus == 1 &&
			flag->flag_zero == 1)
		tmp = ad_0_aftersps(tmp, flag->width - lensps);
	else if (flag->precision > lensps && flag->flag_minus == 0)
		tmp = ad_0_aftersps(tmp, flag->precision - lensps);
	else if (flag->precision > lensps && flag->flag_minus == 1)
		tmp = ad_0_aftersps(tmp, flag->precision - lensps);
	if (flag->width > strln(tmp))
	{
		if (flag->flag_minus == 1)
			tmp = ad_fld_end(tmp, flag->width - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, flag->width - strln(tmp));
	}
	return (tmp);
}
