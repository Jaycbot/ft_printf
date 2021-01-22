/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:41:53 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 21:02:16 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "./libft/libft.h"

# define DEFAULT -1
# define SPEC "nscduixXp%"
# define UTF_8_1B 0x7F
# define UTF_8_2B 0x7FF
# define UTF_8_3B 0xFFFF
# define UTF_8_4B 0x1FFFFF

int				g_error;

typedef struct	s_contents
{
	int	minus;
	int	zero;

	int	precision;
	int	width;
	int	length;
	int	cap;
}				t_contents;

int				ft_printf(const char *format, ...);
int				ret_with_write(char c);
void			check_len(t_contents *contents, const char **format);
void			content_init(t_contents *contents);
int				encode_utf_8(wchar_t unicode);
int				parse_c(t_contents *contents, va_list ap);
int				parse_s(t_contents *contents, va_list ap);
int				parse_u(t_contents *contents, va_list ap);
int				parse_i(t_contents *contents, va_list ap);
int				parse_x(char type, t_contents *contents, va_list ap);
int				parse_p(t_contents *contents, va_list ap);
int				parse_perc(t_contents *contents);
int				no_pre_uni(wchar_t *uni, t_contents *f);
int				no_pre_plain(char *s, t_contents *f);
int				ft_putuni(wchar_t *uni);
int				ft_putstr(char *c);
int				uni_size(wchar_t uni);
int				uni_s_size(wchar_t *uni);
void			print_substr(char const *s, unsigned int start, size_t len);
void			print_uni_substr(wchar_t *uni, size_t len);
int				uni_sub_size(wchar_t *uni, size_t len);
void			pt_print(unsigned long pt, t_contents *f);
void			modify_width(t_contents *f);
int				int_parse(t_contents *f, long long int n, int digit);
void			itoa_free(long long int n);
void			itoa_free_u(unsigned long long n);
void			fill_space(int num, char c);
char			*itoa_without_sign(long long int n);
void			itoa_nosign_free_u(unsigned long long n);
void			itoa_nosign_free(long long int n);
int				print_neg_pre_un(t_contents *f, unsigned long long n, int d);
int				unint_parse(t_contents *f, unsigned long long n, int d);
int				print_pos_pre_un(t_contents *f, unsigned long long n, int d);
char			*itoa_without_sign_u(unsigned long long n);
void			print_hex(unsigned long long hex, int depth, int d, int cap);
int				print_pos_pre_hex(t_contents *f, unsigned long long n, int d);
int				print_neg_pre_hex(t_contents *f, unsigned long long n, int d);
int				cal_digit(long long int num);
int				cal_udigit(unsigned long long num);
int				hex_parse(t_contents *f, unsigned long long n, int digit);
int				is_in(char *s, char c);
void			print_minus(int is_m);
int				size_memory(unsigned long pt, t_contents *f);

#endif
