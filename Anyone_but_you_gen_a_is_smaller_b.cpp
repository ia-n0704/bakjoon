#include "testlib.h"

int ch[200010];
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100'000);
    printf("%d\n",n);
    int a=rnd.next(n,2*n);
    int b;
    do
    {
        b=rnd.next(1,2*n);
    }while(a>=b);
    printf("%d %d\n",a,b);
    int no=0;
    for(int i=1;i<=a/2;i++)
        printf("%d ",i*2-1);
    for(int i=a/2+1;i<a;i++)
    {
        printf("%d",(i-a/2)*2);
        if(i<a-1) printf(" ");
    }
    printf("\n");
}