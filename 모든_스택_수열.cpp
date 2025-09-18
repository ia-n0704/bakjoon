# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
vector<int> ans;
void dfs(vector<int> v,int num,int cnt)
{
    if(cnt>n)
    {
        for(auto i:ans)
            cout<<i<<" ";
        cout<<'\n';
        return;
    }
    // #set_1 : 이전 수 출력
    if(v.size()!=0)
    {
        int a=v.back();
        ans.push_back(a);
        v.pop_back();
        dfs(v,num,cnt+1);
        v.push_back(a);
        ans.pop_back();
    }
    
    // #set_2 : 다음 수를 넣음
    if(num<n)
    {
        v.push_back(++num);
        dfs(v,num,cnt);        
    }
}
int main()
{
    fastio;
    cin>>n;
    vector<int> v;
    v.push_back(1);
    dfs(v,1,1);
}