#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sta[5000],l;
int p=0;
int len=0,ans=0;
char ch[5000];
void test(int ind){
    int temp=0;
    for(int i=0;(((i+ind)<len)&&((ind-i)>=0));i++)
        if (ch[ind+i]==ch[ind-i])
            temp++;
    if (temp>=ans){
        if (temp==ans){
            sta[l++]=ind;
        } else{
            ans = temp;
            l=0; 
            sta[l++]=ind;
        }
    }
}
int main(){
    while((ch[len++]=getchar())!='\n');
    for(int i=0;i<len;i++)
        test(i);
    //printf("%d\n",ans);
    for(int i=0;i<l;i++){
        for(int j=sta[i]-ans+1;j<=sta[i]+ans-1;j++)
            putchar(ch[j]);
        putchar('\n');
    }
    return 0;
}