/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:11:07 by mjalloul          #+#    #+#             */
/*   Updated: 2022/12/30 04:04:30 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		i = -1;
	
		str++;
	}
	while (*(ft_strtrim(str, " \t\n\v\r\f")))
	{
		if(!ft_isdigit(*str))
			return(-1);
		j = (j * 10) + (*str - 48);
		str++;
	}
	return (i * j);
}
