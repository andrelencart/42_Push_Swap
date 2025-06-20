/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_decfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:31 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/11 15:03:43 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_nbr_tf(int nbr)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nbr);
	len = ft_putstrtf(num);
	free (num);
	return (len);
}

static int	ft_ulength(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		n++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_unitoa(unsigned int n)
{
	unsigned int	len;
	char			*str;

	len = ft_ulength(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_put_un_nbr(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len = ft_putchartf('0');
	if (n != 0)
	{
		num = ft_unitoa(n);
		len = ft_putstrtf(num);
		free(num);
	}
	return (len);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
