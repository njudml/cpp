#include <stdio.h>
extern int func(int a);
int main()
{
    int i=func(1);
    printf("%d\n",i);
    return 0;
}
