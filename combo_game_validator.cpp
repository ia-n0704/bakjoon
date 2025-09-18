#include <bits/stdc++.h>
#include "testlib.h"
typedef long long ll;

 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2,200'000,"n");
    inf.readEoln();
    for(int i=0;i<n;i++)
    {
        int c=inf.readInt(1,1'000'000'000'000,"c");
        if(i!=n-1) inf.readSpace();
    }
    inf.readEoln();
    for(int i=0;i<n;i++)
    {
        int c=inf.readInt(1,n,"c");
        ensuref(c==i+1, "attack number [%d] has loop!",i);
        if(i!=n-1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}