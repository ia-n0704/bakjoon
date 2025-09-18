#include "testlib.h"
const int mx=1e9;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100'000);
    int q=rnd.next(1,100'000);
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++)
    {
        printf("%d",rnd.next(1,mx));
        if(i!=n)
            printf(" ");
    }
    printf("\n");
    for(int i=1;i<=q;i++)
    {
        int l=rnd.next(1,n);
        int r=rnd.next(l,n);
        int k=rnd.next(1,mx);
        printf("%d %d %d\n",l,r,k);
    }
}