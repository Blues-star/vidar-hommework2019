#include <stdio.h>


int getElement(int *a, int b, int c)
{
    return *(a+b*16+c);
}
int main()
{
    int a[16][16] = {0};
    int b, c;
    scanf_s("%d %d", &b, &c);
    if (b < 0 || c < 0){
        printf("Error:b or c is invalid\n");
        return 0;
    }
    printf("%d\n", getElement((int *)a, b, c));
    return 0;
}
