# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int arr[600010];
int ch[600010];
int n,k,p;
int idx=1;
int cnt;
int sz;
void go1(int x,int num)
{
    if(x==0) return;
    arr[x]=num;
    ch[num]=1;
    go1(x/2,num-1);
}
void go2(int x)
{
    if(x>n) return;
    while(ch[idx]) idx++;
    if(arr[x]==0)
    {
        arr[x]=idx;
        ch[idx]=1;
    }
    go2(x*2);
    go2(x*2+1);
}
void dfs(int x)
{
    if(x>n) return;
    arr[x]=cnt;
    ch[cnt]=1;
    sz++;
    cnt++;
    dfs(x*2);
    dfs(x*2+1);
}
int main()
{
    fastio;
    cin>>n>>k>>p;
    int temp=p;
    int cntp=0;
    while(temp)
    {
        cntp++;
        temp/=2;
    }

    temp=k;
    int cntk=0;
    while(temp)
    {
        cntk++;
        temp/=2;
    }
    cnt=k;
    dfs(p);
    if(cntp>k || sz-1>n-k)
    {
        cout<<-1;
        return 0;
    }
    go1(p/2,cntp-1);
    //for(int i=1;i<=n;i++) cout<<arr[i]<<'\n';
    go2(1);
    for(int i=1;i<=n;i++) cout<<arr[i]<<'\n';
}