#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int temp;
int sum,m,n;
int flag=0;
int a[6660];
int calc(int tol,int times){
    if (times == 1)
        return(tol+n-1)%tol;
    else{
        return(calc(tol-1,times-1)+n)%tol;
    }
}
int main()
{
    //scanf("%d %d %d",&sum,&n,&m);
    scanf("%d",&sum);
    n=3;m=sum-1;
    int i=0;
    while(++i<=sum-n+1){
        //printf("%d\n",calc(sum,n,i));
        a[calc(sum,i)]=1;

    }
    for(int i=1;i<=n;i++){
        if (a[i]==0)
            printf("%d\n",i);
    }
    return 0;
}