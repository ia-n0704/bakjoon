#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=100'000;
    int m=rnd.next(1,100'000);
    printf("%d %d\n",n,m);
    int sta=rnd.next(1,333'333'333);
    int stb=rnd.next(1,333'333'333);
    int stc=rnd.next(1,333'333'333);
    printf("%d %d %d\n",sta,stb,stc);
    int a=333'333'333,b=333'333'333,c=333'333'333;
    for(int i=1;i<=n;i++)
    {
        a-=rnd.next(0,1'000);
        b-=rnd.next(0,1'000);
        c-=rnd.next(0,1'000);
        printf("%d %d %d\n",a,b,c);
    }
}