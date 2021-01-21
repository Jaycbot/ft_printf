#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int a;
	int b;
	int	*c;

	b = 1;
	c = &b;
	a = ft_printf("%.0d\n", 0);

	return (0);
}
