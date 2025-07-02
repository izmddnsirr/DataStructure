#include <stdio.h>

int main()
{
    int y = 99;
    int *p = &y;
    printf("%d\n", y);
    
    *p = 55;
    printf("%d\n", y);

    return 0;
}
