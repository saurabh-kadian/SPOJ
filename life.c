#include<stdio.h>
int main()
{
    long int i;
    scanf("%ld",&i);
    while(i!=42)
    {
        printf("%ld\n",i);
        scanf("%ld",&i);
    }
    return 0;
}