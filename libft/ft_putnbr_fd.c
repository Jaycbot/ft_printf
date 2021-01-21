/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:43:23 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/24 20:11:36 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	i;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	i = (n % 10) + '0';
	ft_putchar_fd(i, fd);
}
