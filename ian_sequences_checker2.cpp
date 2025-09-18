#include "testlib.h"
#include <sstream>
 
using namespace std;

vector<int> v;
 
pair<int,int> check(int x)
{
    int n=x/2;
    int flag=0;
    for(int i=k+1;i<=n;i++)
    {
        int sum=0;
        for(auto j:v)
        {
            if(j==i)
            {
                if(flag==0)
                    flag=1;
                else flag=0;
            }
            else if(flag)
                sum+=j;
        }
        if(sum%i!=k)
            return {i,sum%i};
    }
    return {0,0};
}
 
int main(int argc, char * argv[])
{
    setName("compare ordered sequences of signed int%d numbers", 8 * sizeof(long long));
 
    registerTestlibCmd(argc, argv);
 
    int n = inf.readInt(1,5000,"n");
    int k = inf.readInt(1,5000,"k");
    
    string firstElems;
 
    while (!ans.seekEof() && !ouf.seekEof())
    {
        //n++;
        int p=ans.readInt(1,5000,"p");
        int q=ouf.readInt(1,5000,"q");
        v.push_back(q);
    }
 
    int extraInAnsCount = 0;
 
    while (!ans.seekEof())
    {
        ans.readInt(1,5000,"n");
        extraInAnsCount++;
    }
    
    int extraInOufCount = 0;
 
    while (!ouf.seekEof())
    {
        ouf.readInt(1,5000,"n");
        extraInOufCount++;
    }
 
    if (extraInAnsCount > 0)
        quitf(_wa, "Answer contains longer sequence [length = %d], but output contains %d elements", n + extraInAnsCount, n);
    
    if (extraInOufCount > 0)
        quitf(_wa, "Output contains longer sequence [length = %d], but answer contains %d elements", n + extraInOufCount, n);
    
    pair<int,int> ans=check(n);

    if (ans.first==0)
    {
        quitf(_ok, "%d number(s)", n);
    }
    else
        quitf(_wa, "j=%d (answer : 1, result : %d)", ans.first,ans.second);
}
