#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100'000);
    int m=rnd.next(1,1'000'000'000);
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        int c=1'000'000'000;
        printf("%d",c);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
}