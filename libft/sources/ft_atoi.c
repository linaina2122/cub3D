/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:58:03 by bkamal            #+#    #+#             */
/*   Updated: 2023/04/14 03:14:22 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isempty(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 9223372036854775807 && sign == -1)
			return (0);
		if (nb >= 9223372036854775807 && sign == 1)
			return (-1);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	ft_color_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = -1;
	nbr = 0;
	while (str[++i] && ft_isdigit(str[i]) && nbr <= 255)
		nbr = nbr * 10 + (str[i] - '0');
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	return (nbr);
}
