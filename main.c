#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int a;
	int b;
	int	*c;

	b = 1;
	c = &b;
	a = ft_printf("%d", -30);

	printf("\n%d", a);
	return (0);
}
