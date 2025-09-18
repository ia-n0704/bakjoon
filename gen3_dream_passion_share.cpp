#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=100'000;
    int m=100'000;
    printf("%d %d\n",n,m);
    int sta=333'333'333;
    int stb=333'333'333;
    int stc=333'333'333;
    printf("%d %d %d\n",sta,stb,stc);
    for(int i=1;i<=n;i++)
    {
        int a=rnd.next(1,333'333'333);
        int b=rnd.next(1,333'333'333);
        int c=rnd.next(1,333'333'333);
        printf("%d %d %d\n",a,b,c);
    }
}