#include "testlib.h"

int ch[200010];
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100'000);
    printf("%d\n",n);
    int a=rnd.next(1,2*n);
    int b;
    do
    {
        b=rnd.next(1,2*n);
    }while(a==b);
    printf("%d %d\n",a,b);
    int no=0;
    for(int i=1;i<a;i++)
    {
        int x;
        do
        {
            x=rnd.next(1,2*n);
        }while(ch[x] || x==no);
        if(i==b)
        {
            if(x%2) no=x+1;
            else no=x-1;
        }
        ch[x]=1;
        printf("%d",x);
        if(i<a-1) printf(" ");
    }
    printf("\n");
}