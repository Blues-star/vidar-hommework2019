#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n;
void output(int lr,int mid,int ind){
    if (mid>n)
        return ;
    int temp = lr;
    while(temp--)
        putchar(' ');
    for(int i=1;i<=mid;i++)
        putchar('*');
    temp = lr;
    while(temp--)
        putchar(' ');
    putchar('\n');
    output(lr-1,mid+2,ind+1);
}
int main(){
    scanf("%d",&n);
    output(n/2,1,1);
    return 0;
}