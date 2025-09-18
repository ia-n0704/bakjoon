#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
int ch[200010];
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1,100'000,"n");
    inf.readEoln();
    int a = inf.readInt(1,2*n,"a");
    inf.readSpace();
    int b = inf.readInt(1,2*n,"b");
    inf.readEoln();
    ensuref(a!=b, "A is equal to B");
    int no=0;
    for(int i=1;i<a;i++)
    {
        int x=inf.readInt(1,2*n,"x");
        ensuref(!ch[x], "students can't choose same seat");
        ensuref(no!=x, "others can't seat next to chaewon");
        if(i==b)
        {
            if(x%2) no=x+1;
            else no=x-1;
        }
        ch[x]=1;
        if(i<a-1) inf.readSpace();
    }
    if(a>1) inf.readEoln();
    inf.readEof();
}