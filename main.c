#include <stdio.h>

int main( )
{
        int a;
        int b;
        a = ft_printf("Print: %-10.10d\n", -204);
        printf("%d\n", a);
        b = printf("Print: %-10.10d\n", -204);
        printf("%d\n", b);
}
