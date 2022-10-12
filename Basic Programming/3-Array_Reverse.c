/*Program to read n number of values in an array and display
it in reverse order. */

#include <stdio.h>
int main()
{
    int len, arr[100], i;
    printf("Enter the length of the array:");
    scanf("%d", &len);
    printf("Enter the elements of the array:");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = len - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}