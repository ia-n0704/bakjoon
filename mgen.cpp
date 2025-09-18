#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    cout<<n<<'\n';
    for(int i=1;i<n;i++)
        cout<<"1 "<<i<<'\n';
    for(int i=1;i<=n;i++)
        cout<<rnd.next(1,1'000'000'000)<<" ";
    cout<<'\n';
    return 0;
}