#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100'000, "n");
    inf.readSpace();
    int q = inf.readInt(1, 100'000, "q");
    inf.readEoln();
    for(int i=1;i<=n;i++)
    {
        inf.readInt(1,1e9,"arr");
        if(i!=n)
            inf.readSpace();
    }
    inf.readEoln();
    for(int i=1;i<=q;i++)
    {
        int l=inf.readInt(1,n,"l");
        inf.readSpace();
        inf.readInt(l,n,"r");
        inf.readSpace();
        inf.readInt(1,1e9,"k");
        inf.readEoln();
    }
    inf.readEof();
}