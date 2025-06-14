#include "stdlib.h"
#include "stdio.h"
int main()
{
    int a = 5, b = 4;
    int A = !(a&b);
    int B =!(a|b);
    int C = !b||!a;
    int D = !a&&!b;
    printf("%d, %d, %d, %d\n", A, B, C, D);
    return 0;
}