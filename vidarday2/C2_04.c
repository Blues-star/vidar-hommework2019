#include <stdio.h>
#include <string.h>

int mystrcmp(const char *s1, const char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2){
        return -1;
    }
    for(int i = 0; i < len1;i++){
        if(s1[i] != s2[i]){
            return -1;
        }
    }
    char * a = (char *)s1;
    for(int i = 0; i <len1;i++){
        a[i]+=1;
    }
    return 0;
}

int main(){
    char a[4] = "abc";
    char b[4] = "abc";
    puts(a);
    printf("%d\n",mystrcmp(a,b));
    puts(a);
    return 0;
}