#include <stdio.h>

void foo3(int *arr)
{
    arr[1] -= 3;
}

void foo2(int *arr)
{
    arr[1] += 11;
}

void foo1(int *arr)
{
    foo2(arr);
    foo3(arr);
}

int main (void)
{
    int arr[3];
    
    arr[0] = 7;
    arr[1] = 5;
    arr[2] = 3;
    foo1(arr);
    int i = 0;
    while (i < 3)
        printf("%d\n", arr[i++]);
    return (0);
}