/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_flags_with_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:14:10 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 12:14:37 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*work_flags_with_s(t_flag *flag, char *tmp)
{
	char	*ptr;

	ptr = tmp;
	if (flag->precision < strln_s(ptr) && flag->prec == 1)
	{
		ptr = ft_strsub(tmp, 0, flag->precision);
		free(tmp);
	}
	if (flag->width > strln(ptr) && flag->width > 1)
	{
		if (flag->flag_minus == 1)
			ptr = ad_fld_end(ptr, flag->width - strln(ptr));
		else
			ptr = ad_fld_strt(ptr, flag->width - strln(ptr));
	}
	return (ptr);
}
