#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=100'000;
    int m=1'000'000'000;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        int c=rnd.next(900'000'000,1'000'000'000);
        printf("%d",c);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
}