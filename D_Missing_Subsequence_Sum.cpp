# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    vector<int> ans;
    int n,m;
    cin>>n>>m;
    int num=0;
    int idx=0;
    int flag=0;
    int c=0;
    if(m==1)
    {
        ans.push_back(2);
        ans.push_back(3);
        ans.push_back(4);
        num=9;
        idx=10;
        flag=1;
        c=1;
    }
    while(num<=n && idx<=n)
    {
        if(flag==0 && num+num+idx+1>=m)
        {
            if(m-num-1>0)
                ans.push_back(m-num-1-c);
            num=m-1;
            flag=1;
            idx=m+1;
            num+=idx;
        }
        else
        {
            idx=num+1;    
            num+=idx;      
        }
        ans.push_back(idx-c);
    }
    if(ans.size()>25)
    {
        cout<<25<<'\n';
        for(int i=0;i<25;i++) cout<<ans[i]<<" ";
        cout<<'\n';
        return;
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i<<" ";
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}