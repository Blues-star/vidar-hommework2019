#include <stdio.h> 
#include <string.h>

int comp(char *a,char *b){
    for(int i=0;i<4;i++){
        if (a[i]!=b[i])
            return 0;
    }
    return 1;
}
int n;
int main()
{
    char *a = "896750634d67e847da665373db6707774c63e466";
    
    char passwd[] = "y0uzh1yu4n";
    char key[] = "helloworld";
    char part1[11];
    char part2[11];

    char temp[155];
    for (int i = 0; i < strlen(passwd); i++)
    {
        part1[i] = (passwd[i] & 0x55) | (key[i] & 0xaa);
        part2[i] = (passwd[i] & 0xaa) | (key[i] & 0x55);
        printf("%02x", ((part2[i] & 0xf) << 4) | (part1[i] & 0xf));
        printf("%02x", (part2[i] & 0xf0) | ((part1[i] & 0xf0) >> 4));
    }
    /*for(int ind=0;ind<10;ind++){
        char q[5];
        for(int t=0;t<4;t++){
            q[t]=a[t];
        }
        q[4]='\0';
        puts(q);
        putchar ('\n');
        a+=4;
        for(int m=32;m<=126;m++){
            part1[ind] = (m & 0x55) | (key[ind] & 0xaa);
            part2[ind] = (m & 0xaa) | (key[ind] & 0x55);
            sprintf(temp,"%02x", ((part2[ind] & 0xf) << 4) | (part1[ind] & 0xf));
            sprintf(temp+2,"%02x", (part2[ind] & 0xf0) | ((part1[ind] & 0xf0) >> 4));
            temp[4]='\0';
            //puts(temp);
            //return 0;
            //putchar('\n');
            if (comp(temp,q)){
                printf("get :%c\n",m);
            }
            //scanf("%d",&n);
        }
    }   */
    
}

//y0uzh1yu4n