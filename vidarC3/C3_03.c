#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define _tot 655
#define DEBUG 0
#define OUTPUT 0
//OUTPUT是即时回显开关
struct elem{
    char op;
    double val;
}list[_tot];
int listcount=0;
//list存放词法分析后的计算式
char ch;
char csta[_tot];
//csta存放读入并去除空格后的字符串
int len;
struct elem cl[_tot];
//cl存储后缀转换后的字符串
int clen;


struct data{
    char name[512];
    double value;
}M[_tot];

int weight(char ch, int flag)
{
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '(' && flag == 1) return 0;
    if (ch == '(' && flag == 0) return 3;
}

typedef struct
{
    struct elem s[_tot];
    int top;
}ss;

void clearelem(struct elem *m){
    m->op='\0';
    m->val=0;
}

void trans()
{
    //将中缀elem串转化为后缀elem串
    ss a;
    a.top = -1;
    int i, f = 0;
    for (i = 0; i < listcount; i++){
            if (list[i].op==0){
                //是操作数，直接输出
                if (DEBUG)
                    printf("%.1lf", list[i].val);
                cl[++clen]=list[i];
                continue;
            }
            if (a.top == -1){
                a.s[++a.top] = list[i];
                continue;
            }
            if (list[i].op == ')'){
                while (a.top != -1 && a.s[a.top].op != '('){
                    //cl[++clen]=a.s[a.top];
                    if (DEBUG)
                        printf("%c", a.s[a.top].op);
                    cl[++clen]=a.s[a.top];
                    a.top--;
                }
                    //减去左括号
                    --a.top;
                    continue;
                }
            if (weight(list[i].op, 0) > weight(a.s[a.top].op, 1)){
                a.s[++a.top] = list[i];
                continue;
            }
            while (a.top != -1 && weight(list[i].op, 0) <= weight(a.s[a.top].op, 1)){
                //cl[++clen]=a.s[a.top];
                if (DEBUG)
                    printf("%c", a.s[a.top].op);
                cl[++clen]=a.s[a.top];
                --a.top;
                f = 1;
            }
            if (f == 1){
                a.s[++a.top] = list[i];
                f = 0;
            };
    }
    while (a.top != -1){
        //cl[++clen]=a.s[a.top];
        cl[++clen]=a.s[a.top];
        if (DEBUG)
            printf("%c", a.s[a.top].op);
        a.top--;
        
    }
    if(DEBUG)
        putchar('\n');
}

double getans(double a,double b,char op){
    if (op=='*')
        return a*b;
    if (op=='+')
        return a+b;
    if (op=='-')
        return a-b;
    if (op=='/')
        return a/b;
}

double temp[3627] = {0};
double calcs(){
    //计算后缀elem串的值
    int top = 0;
    if (clen==1){
        return cl[1].val;
    }
    for(int i=1;i<=clen;i++){
        if (cl[i].op==0){
            temp[top++]=cl[i].val;
            continue;
        }else{
            double a = temp[--top];
            double b = temp[--top];
            double ans = getans(b,a,cl[i].op);
            temp[top++]=ans;
        }
    }
    return temp[0];
}

unsigned int _hash(char *t){
    //printf("%d\n",strlen(t));
    if (strlen(t)==1){
        return *t*13131;
    }
    char * _t = (char *)malloc(sizeof(char)*660);
    strcpy(_t,t);
    unsigned int hash = 0;
    int c=0;
    while(*(_t+c)){
        hash = (hash * 13131) + (*(_t+c)); // 31 131 1313 13131 131313 etc...
        c++;
    }
    free(_t);
    return hash;
}

int _compare(char *a,char *b){
    if (strlen(a)!=strlen(b))
        return -1;
    for(int i=0;i<strlen(a);i++){
        if (a[i]!=b[i])
            return -1;
    }
    return 0;
}
int isget = 0;
int _succeed = 0;
double* sfind(char* s){
    //查找字符串s对应的变量值
    unsigned temp = _hash(s);
    temp%=_tot;
    if (M[temp].name[0]=='\0'){
        if (isget==1){
            _succeed = 0;
            return 0;
        }
        strcpy(M[temp].name,s);
        M[temp].value = 0;
        //包含变量未声明的情况，TODO
        _succeed = 1;
        return &M[temp].value;
    }
    while(_compare(M[temp].name,s)==-1){
        temp++;
    }
    return &M[temp].value;
}

int isop(char ch){
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')')
        return 1;
    return 0;
}
int lastop=1;
int scan(struct elem *dst,int begin){
    //扫描字符串，每次返回一个elem
    //for(int i=begin;i<strlen(csta);i++){
    int ind=begin;
    while(ind<strlen(csta)){
        if (csta[ind]=='\0'){
            _succeed=1;
            return strlen(csta);
        }
            
        if (isop(csta[ind])){
            if (!(csta[ind]=='-' && lastop==1)){
                dst->op=csta[ind];
                lastop=1;
                _succeed=1;
                return ind+1;
            }
        }
        if (isdigit(csta[ind]) || (csta[ind]=='-' && lastop==1)){
            sscanf(csta+ind,"%lf",&(dst->val));
            if (csta[ind]=='-')
                ind++;
           // printf("接收到 %.2lf\n",dst->val);
            while(isdigit(csta[ind]) || csta[ind]=='.') 
                ind++;
            lastop=0;
            _succeed=1;
            return ind;
        }
        if (isalpha(csta[ind])){
            //char temp[250];
            char * temp = (char *)malloc(sizeof(char)*256);
            int _len=0;
            while(isalpha(csta[ind])){
                temp[_len++]=csta[ind];
                ind++;
            }
            temp[_len]='\0';
            isget = 1;
            double* ans = sfind(temp);
            if (_succeed==0){
                printf("error : undified variable name \"%s\"\n",temp);
                return 0;
            }
            clearelem(dst);
            dst->val=*ans;
            lastop=0;
            _succeed=1;
            free(temp);
            return ind;
        }
    }
    return 0;
}

int checkexit(){
    char a[5]= "exit";
    for(int i=0;i<4;i++){
        if (csta[i]!=a[i])
            return 0;
    }
    return 1;
}   

int read_line(){
    while ((ch = getchar()) != '\n' && len<256){
            if (ch == ' ')
                continue;
            csta[len++] = ch;
        }
    if (len==256){
        _succeed=0; 
        printf("input too long\n");
        return 0;
    }
    csta[len] = '\0';
    if (checkexit()){
        exit(0);
    }
    _succeed=1;
    return len;
}

int analyze(){
    //分析输入的行，并将表达式转换为elem节点串
    _succeed=1;
    int begin = 0;
    int isequal = 0;
    for(int i=0; i<len;i++){
        if (csta[i]=='='){
            begin=i+1;
            break;
        }
    }
    if (begin==0){
        isequal=0;
    } else{
        isequal=1;
    }
    while(begin<len){
        clearelem(&list[listcount]);
        begin = scan(&list[listcount],begin);
        if (_succeed==0){
            listcount=0; 
            return -1;
        }
        listcount++;
    }
    return isequal;
}   

int check(char a){
    if(isdigit(a))
        return 1;
    if (isalpha(a))
        return 1;
    if (a=='_')
        return 1;
    return 0;
}

int checkname(char *name){
    char * t = (char *)malloc(sizeof(char)*512);
    t = name;
    if (*t>='0' && *t<='9')
        return 0;
    while(*t){
        if (check(*t)==0){
            return 0;
        }
        t++;
    }
    return 1;
}

void init(){
    clen=0;
    len=0;
    listcount=0;
    _succeed=1;
}

int main()
{
    //freopen("input.in","r",stdin);
    while(1){
        init();
        _succeed=0;
        len = read_line();
        if (_succeed==0){
            init();
            continue;
        }
        if (len==0)
            continue;
        _succeed=0;
        int isequal = analyze();
        if (isequal==-1){
            init();
            continue;
        }
        trans();
        double ans = calcs();
        if (isequal){
            char *t = (char *)malloc(sizeof(char)*512);
            int i;
            for(i=0;csta[i]!='=';i++)
                t[i]=csta[i];
            t[i]='\0';
            isget=0;
            if (checkname(t)==0){
                printf("error : Illegal variable name \"%s\"\n",t);
                free(t);
                continue;
            }
            double *val = sfind(t);
            *val = ans;
            free(t);
            if (DEBUG || OUTPUT) 
                printf("%lf\n",ans);
        } else{
            printf("%lf\n",ans);
        }
    }
    return 0;
}