/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:41:53 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/19 00:53:44 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "./libft/libft.h"

# define DEFAULT -1
# define SPEC "scduixXp%"
# define UTF_8_1B 0x7F
# define UTF_8_2B 0x7FF
# define UTF_8_3B 0xFFFF
# define UTF_8_4B 0x1FFFFF

typedef struct	s_contents
{
	int	minus;
	int	zero;

	int	precision;
	int	width;
	int	length;
}				t_contents;

int				ft_printf(const char *format, ...);
int				ret_with_write(char c);
void			check_len(t_contents *contents, const char **format);
void			content_init(t_contents *contents);
int				encode_utf_8(wint_t unicode);
int				parse_c(t_contents *contents, va_list ap);
int				parse_s(t_contents *contents, va_list ap);
int				parse_u(t_contents *contents, va_list ap);
int				parse_i(t_contents *contents, va_list ap);
int				parse_x(char type, t_contents *contents, va_list ap);
int				parse_p(t_contents *contents, va_list ap);
int				parse_perc(t_contents *contents);

#endif
