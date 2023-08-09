#include <stdio.h>
void main()
{
    int a[] = {10, 20, 30, 40};
    int j;
    int *p = a + 3;
    for (j = 3; j >= 0; j--)
    {
        printf("%d ", --*p);
        p = p - 1;
    }
}