/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_flags_with_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:22:21 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 13:30:55 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*third_step_part2(t_flag *flag, char *tmp)
{
	if (flag->width > strln(tmp))
	{
		if (flag->flag_zero == 1)
		{
			if (flag->flag_minus == 1)
				tmp = ad_fld_end(tmp, flag->width - strln(tmp));
			else
				tmp = ad_0_aftersps(tmp, flag->width - strln(tmp));
		}
		else
		{
			if (flag->flag_minus == 1)
				tmp = ad_fld_end(tmp, flag->width - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, flag->width - strln(tmp));
		}
	}
	return (tmp);
}

char	*third_step_for_f(t_flag *flag, char *tmp)
{
	if (flag->precision == 0 && flag->prec == 0)
	{
		if (flag->flag_zero == 1)
		{
			if (flag->width > strln(tmp))
				tmp = ad_0_aftersps(tmp, flag->width - strln(tmp));
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
		tmp = third_step_part2(flag, tmp);
	return (tmp);
}

char	*second_step_for_f(char *tmp)
{
	int		count;
	char	*new;

	count = 0;
	new = NULL;
	if (count_af_dot(tmp) == 0)
		new = ft_strjoin(tmp, ".000000");
	else if (count_af_dot(tmp) > 0 && count_af_dot(tmp) < 6)
	{
		count = 6 - count_af_dot(tmp);
		new = ft_strjoin(tmp, "0");
		while (count != 1)
		{
			new = ft_strjoin_free(new, "0");
			count--;
		}
	}
	if (count_af_dot(tmp) >= 6)
	{
		free(new);
		return (tmp);
	}
	free(tmp);
	return (new);
}

char	*first_step_for_f(t_flag *flag, char *tmp)
{
	char *ptr;

	ptr = NULL;
	if (flag->flag_plus == 1)
	{
		if (tmp[0] != '-')
		{
			ptr = ft_strjoin("+", tmp);
			free(tmp);
			return (ptr);
		}
	}
	else if (flag->flag_space == 1)
	{
		if (tmp[0] != '-')
		{
			ptr = ft_strjoin(" ", tmp);
			free(tmp);
			return (ptr);
		}
	}
	return (tmp);
}

char	*work_flags_with_f(t_flag *flag, char *tmp)
{
	tmp = first_step_for_f(flag, tmp);
	tmp = second_step_for_f(tmp);
	tmp = step_precis_for_f(flag, tmp);
	tmp = third_step_for_f(flag, tmp);
	return (tmp);
}
