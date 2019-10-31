#include <stdio.h>
#include <string.h>
#pragma pack(push)
#pragma pack(8)
typedef struct
{
    char a;
    unsigned long long b;
} aaa;
#pragma pack(pop)

int main()
{
    aaa ddd;
    printf("%ld %ld %ld\n", sizeof(ddd.a), sizeof(ddd.b), sizeof(ddd));
    return 0;
}


/*
    pack(push) 将保存当前对齐状态，
    pack(8) 表示将对齐字节设置为8位
    用aaa来说明，aaa.a占用一个字节，aaa.b占用8个字节，为了对齐，aaa.a会留出7个字节的空间，再存放aaa.b，保证结构体空间是8的倍数，这样，sizeof(aaa)就是16个字节了。
    pragma pack(pop)表示恢复对齐状态


*/