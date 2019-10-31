#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int p[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int y, m;
int main(){
    scanf("%d.%d", &y, &m);
    int ans = 0;
    if ((((y%4==0)&&(y%100!=0))||(y%400==0))&&(m==2)){
        ans = p[m]+1;
    } else{
        ans = p[m];
    }
    printf("%d",ans);
    return 0;
}