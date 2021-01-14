/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:41:53 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/15 02:08:26 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define DEFAULT -1

typedef struct      s_contents
{
    int minus;
    int zero;

    int precision;
    int width;
}                   t_contents;

int ft_printf(const char *format, ...);

#endif
