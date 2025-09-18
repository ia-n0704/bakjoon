#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(1,1'000);
    int m=rnd.next(n,1'000);
    printf("%d %d\n",n,m);
}