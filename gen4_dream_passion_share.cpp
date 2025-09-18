#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100'000);
    int m=1;
    printf("%d %d\n",n,m);
    int sta=rnd.next(1,333'333'333);
    int stb=rnd.next(1,333'333'333);
    int stc=rnd.next(1,333'333'333);
    printf("%d %d %d\n",sta,stb,stc);
    for(int i=1;i<=n;i++)
    {
        int a=rnd.next(1,333'333'333);
        int b=rnd.next(1,333'333'333);
        int c=rnd.next(1,333'333'333);
        printf("%d %d %d\n",a,b,c);
    }
}