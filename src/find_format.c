/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:34:31 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 12:38:23 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int			ft_if_supported(char *stringformat)
{
	size_t index;

	index = 0;
	if (!stringformat)
		return (0);
	while (stringformat[index])
	{
		if (!ft_strchr(SUPPORTED, stringformat[index]))
			return (0);
		index++;
	}
	return (1);
}

static	void		free_struct(t_flag *flag)
{
	if (flag->format)
		free(flag->format);
	if (flag->format_mod)
		free(flag->format_mod);
	free(flag);
}

size_t				ft_find_format(const char **format, char **temp, va_list ap)
{
	int			index;
	size_t		size;
	char		*stringformat;
	t_flag		*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	index = ft_get_mods(*format, &stringformat);
	*format += index;
	if (!(ft_if_supported(stringformat)) || stringformat == 0)
	{
		free(flag);
		size = ft_strlen(stringformat);
		if (stringformat)
			free(stringformat);
		return (size);
	}
	ft_analyze_format(stringformat, flag, ap);
	*temp = format_processing(flag, ap);
	size = strlen_bytes(*temp, flag);
	free(stringformat);
	free_struct(flag);
	stringformat = NULL;
	return (size);
}
