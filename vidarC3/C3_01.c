#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct student{
    int id;
    char name[12];
    struct student* next;
};


int main(){
    struct student a;
    a.id = 15435;
    strcpy(a.name,"helloworld");
    a.next = &a;
    void* p = &a;
    void* pa = &a;//不知道干嘛用
    void* pStudent = &a;//不知道干嘛用
    printf("%d\n",*((int*)p));
    printf("%s\n",(char *)(p+4));
    printf("%X\n",*((struct student **)(p+4+12)));
    printf("%p\n",&a);
    return 0;
}