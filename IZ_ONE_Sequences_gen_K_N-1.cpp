#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(2, 200'000);
    int m=n-1;
    printf("%d %d\n",n,m);
}