#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int a;
	int b;
	int	*c;

	b = 1;
	c = &b;
	a = ft_printf("%04.*d\n", 1,198);

	return (0);
}
