#include "testlib.h"

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a>b) return b;
    return a;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100'000);
    int m=rnd.next(1,1'000'000'000);
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        int c=rnd.next(max(1,m/n-2*n),min(1'000'000'000,m/n+n));
        printf("%d",c);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
}