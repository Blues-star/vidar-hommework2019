#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int clac(int x){
    int temp=0,ans=0;
    while(x){
        temp = x%10;
        ans += temp*temp*temp;
        x/=10;
    }
    return ans;
}

int main(){
    for(int i=100;i<1000;i++){
        if (clac(i)==i){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}