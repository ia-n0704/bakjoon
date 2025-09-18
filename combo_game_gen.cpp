#include "testlib.h"
#include <bits/stdc++.h>
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(2,200'000);
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int c;
        c=rnd.next(1,1'000'000'000);
        printf("%d",c);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        int c;
        do
        {
            c=rnd.next(1,n);
        }while(c==i+1);
        printf("%d",c);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
}