#include <stdio.h>
#include <locale.h>
int main(void)
{
    // int b = 0;
    int k = 0;
    setlocale(LC_ALL, "ko_KR.UTF-8");
    // unsigned int a = L'안';
    // b = printf("%4lc", a);
    // printf("%d",b);
    // if (b < 0)
    //     perror("printf");
    // while (0)
    //     printf("11");
    // char *s = "(null)";
    // if ((k = printf("%.4ls",L"안녕")) < 0)
    //     perror("printf");

    // // printf("%.2lc", L'안');
    // int *kp = &k;
    // printf("%.p", kp);
    k = printf("%3d",-1);
    printf("\n");
    printf("%d\n",k);
    return (0);
}