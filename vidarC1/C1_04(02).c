#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int n;
int calc(int x,int y){
    return ((n-x)*(n-x)+(n-y)*(n-y)-(n*n))<0?-((n-x)*(n-x)+(n-y)*(n-y)-(n*n)):((n-x)*(n-x)+(n-y)*(n-y)-(n*n));
}
int pd(int x,int y){
    int t1 = calc(x+1,y);
    int t2 = calc(x+1,y+1);
    int t3 = calc(x,y+1);
    if (t1<t2){
        return t1<t3?1:3;
    } else{
        return t2<t3?2:3;
    }
}
int fi(int x,int y, char m[n*2+1][n*2+1]){
    if ((x==2*n)&&(y==n)){
        m[x][y]='*';
        return 0;
    }
    if (x<2*n){
        int t = pd(x,y);
        switch (t){
            case 1:{
                m[x+1][y]='*';
                fi(x+1,y,m);
            }
            break;
            case 2:{
                m[x+1][y+1]='*';
                fi(x+1,y+1,m);
            }
            break;
            case 3:{
                m[x][y+1]='*';
                fi(x,y+1,m);
            }
            break;
        }
    } else{
        m[x][y]='*';
        fi(x,y+1,m);
    }
    return 0;
}
int main(){
    scanf("%d", &n);
    char m[n*2+1][n*2+1];
    memset(m, 0, sizeof(m));
    m[n][0]='*';
    fi(n,0,m);
    for(int i=0;i+n<=2*n;i++)
        for(int j=0;j<=n;j++)
            if (m[i+n][j]=='*')
                m[n-i][j]='*';
    for(int i=0;i<=2*n;i++)
        for(int j=0;j+n<=2*n;j++)
            if (m[i][n-j]=='*')
                m[i][n+j]='*';
    for(int i=0; i<=2*n;i++){
        for(int j=0; j<=2*n; j++){
            putchar(m[i][j]);
        }
        putchar('\n');
    }
    return 0;
}