/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:41:53 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/16 04:45:11 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define DEFAULT -1
# define SPEC "scduixXp%"

typedef struct      s_contents
{
    int minus;
    int zero;

    int precision;
    int width;
}                   t_contents;

int     ft_printf(const char *format, ...);
int	    ret_with_write(char c);
void    content_init(t_contents *contents);
int     parse_c(t_contents *contents, va_list ap);
int     parse_s(t_contents *contents, va_list ap);
int     parse_u(t_contents *contents, va_list ap);
int     parse_i(t_contents *contents, va_list ap);
int     parse_x(char type, t_contents *contents, va_list ap);
int     parse_p(t_contents *contents, va_list ap);

#endif
