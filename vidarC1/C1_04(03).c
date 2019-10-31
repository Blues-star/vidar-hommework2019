#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
const int de=30;
int n;
int p[61][61];
char m[61][61];
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
double calc(double x,double y){
    return ((double)x*x+(y-pow(x*x,1.0/3.0))*(y-pow(x*x,1.0/3.0))-1)-(9e-1); 
}
int fi(int x,int y, char m[61][61],int p[61][61]){
    if (calc(0.1*x,0.1*y)>0){
        return 0;
    }
    if (p[x+de][y+de]==0){
        m[x+de][y+de]='*';
        p[x+de][y+de]=1;
        for(int i=0;i<8;i++){
            fi(x+dx[i],y+dy[i],m,p);
        }
    }
}
int main(){
    fi(0,0,m,p);
    for(int i=61;i>=0;i--){
        for(int j=0;j<61;j++){
            putchar(m[j][i]);
            putchar(m[j][i]);
            
        }
        putchar('\n');
    }
    return 0;
}