#include "testlib.h"
#include <sstream>
 
using namespace std;
typedef long long ll;

vector<ll> v;
int ch[200010];
ll sum[400010];
 
pair<int,ll> check()
{
    for(int i=0;i<v.size();i++)
    {
        int idx=i+1;
        sum[idx]=sum[idx-1]+v[i];
        if(v[i]==1) continue;
        if(ch[v[i]])
        {
            if((sum[idx-1]-sum[ch[v[i]]])%v[i]!=1)
                return {v[i],(sum[idx-1]-sum[ch[v[i]]])%v[i]};
            continue;
        }
        ch[v[i]]=idx;
    }
    return {0,0};
}
 
int main(int argc, char * argv[])
{
    setName("compare ordered sequences of signed int%d numbers", 8 * sizeof(long long));
 
    registerTestlibCmd(argc, argv);
 
    int n = inf.readInt(1,200'000,"n");
    
    string firstElems;
 
    while (!ans.seekEof() && !ouf.seekEof())
    {
        //n++;
        int p=ans.readInt(1,200'000,"p");
        int q=ouf.readInt(1,200'000,"q");
        v.push_back(q);
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
    
    pair<int,int> ans=check();

    if (ans.first==0)
    {
        quitf(_ok, "%d number(s)", n);
    }
    else
        quitf(_wa, "j=%d (answer : 1, result : %lld)", ans.first,ans.second);
}
