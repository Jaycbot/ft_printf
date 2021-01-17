#include <stdio.h>
#include <locale.h>
int main(void)
{
    int b = 0;
    setlocale(LC_ALL, "ko_KR.UTF-8");
    unsigned int a = L'안';
    b = printf("%lc", a);
    printf("%d",b);
    if (b < 0)
        perror("printf");
    return (0);
}