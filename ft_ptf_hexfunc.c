/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_hexfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:25 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/11 15:03:48 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_nbr_base(unsigned int nbr, char *base)
{
	unsigned int	result;
	size_t			len;
	char			c;

	result = 0;
	len = ft_strlen(base);
	if (nbr >= len)
	{
		result += ft_put_nbr_base(nbr / len, base);
		result += ft_put_nbr_base(nbr % len, base);
	}
	else
	{
		c = base[nbr];
		result += write(1, &c, 1);
	}
	return (result);
}

static int	ft_put_nbr_ptr(uintptr_t nbr, char *base)
{
	unsigned int		result;
	size_t				len;
	char				c;

	result = 0;
	len = ft_strlen(base);
	if (nbr >= len)
	{
		result += ft_put_nbr_ptr(nbr / len, base);
		result += ft_put_nbr_ptr(nbr % len, base);
	}
	else
	{
		c = base[nbr];
		result += write(1, &c, 1);
	}
	return (result);
}

int	ft_put_ptr(uintptr_t ptr)
{
	int	print;

	print = 0;
	if (!ptr)
		print += write(1, "(nil)", 5);
	else
	{
		print += write(1, "0x", 2);
		print += ft_put_nbr_ptr(ptr, HEX_LB);
	}
	return (print);
}

static int	ft_length(long n)
{
	long	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		n++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_length(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (len >= 0 && nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
