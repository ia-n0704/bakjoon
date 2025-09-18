#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1,100'000,"n");
    inf.readSpace();
    int m = inf.readInt(1,n,"m");
    inf.readEoln();
    ensuref(m<=n, "m is bigger than n");
    for(int i=0;i<=n;i++)
    {
        int a=inf.readInt(1,100'000'000,"a");
        inf.readSpace();
        int b=inf.readInt(1,100'000'000,"b");
        inf.readSpace();
        int c=inf.readInt(1,100'000'000,"c");
        inf.readEoln();
    }
    inf.readEof();
}