/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:15:29 by mjalloul          #+#    #+#             */
/*   Updated: 2022/12/30 22:16:29 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}
