#include "testlib.h"
#include <sstream>
 
using namespace std;
typedef long long ll;

vector<ll> v;
int ch[200010];
int n,k;
 
int check()
{
    int l=0,r=n-1;
    while(1)
    {
        while(ch[v[l]]) l++;
        while(ch[v[r]]) r--;
        if(l==r)
            return v[l];
        int t=(v[l]+v[r])/2;
        if(ch[t])
            ch[v[r]]=1;
        else ch[t]=1;
    }
}
 
int main(int argc, char * argv[])
{
    setName("compare ordered sequences of signed int%d numbers", 8 * sizeof(long long));
 
    registerTestlibCmd(argc, argv);
 
    n = inf.readInt(1,200'000,"n");
    k = inf.readInt(1,n,"k");
    
    string firstElems;
 
    while (!ans.seekEof() && !ouf.seekEof())
    {
        int p=ans.readInt(-1,200'000,"p");
        int q=ouf.readInt(-1,200'000,"q");
        v.push_back(q);
    }

    if(n<5 && k==n-1)
    {
        if(v[0]==-1)
            quitf(_ok, "%d number(s)", n);
        else quitf(_wa, "answer couldn't be generated");
    }

    int extraInAnsCount = 0;
 
    while (!ans.seekEof())
    {
        ans.readInt(1,200'000,"n");
        extraInAnsCount++;
    }
    
    int extraInOufCount = 0;
 
    while (!ouf.seekEof())
    {
        ouf.readInt(1,200'000,"n");
        extraInOufCount++;
    }
 
    if (extraInAnsCount > 0)
        quitf(_wa, "Answer contains longer sequence [length = %d], but output contains %d elements", n + extraInAnsCount, n);
    
    if (extraInOufCount > 0)
        quitf(_wa, "Output contains longer sequence [length = %d], but answer contains %d elements", n + extraInOufCount, n);
    
    int ans=check();

    if (ans==k)
    {
        quitf(_ok, "%d number(s)", n);
    }
    else
        quitf(_wa, "answer : %d, result : %d", k, ans);
}
