#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1, 200'000);
    int m=rnd.next(1,n);
    printf("%d %d\n",n,m);
}