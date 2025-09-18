# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
struct line
{
    int x1,y1,x2,y2;
};
pair<int,int> arr[1010];
vector<int> v[1010];
int ch[1010];
int flag;
line L[1010];
int ccw(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int ans=(x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3);
    if(ans>0) return 1;
    else if(ans==0) return 0;
    else return -1;
}
int intersect(line a,line b)
{
    pair<int,int> p1={a.x1,a.y1};
    pair<int,int> p2={a.x2,a.y2};
    pair<int,int> p3={b.x1,b.y1};
    pair<int,int> p4={b.x2,b.y2};
    
    int temp1=ccw(p1.first,p1.second,p2.first,p2.second,p3.first,p3.second)*ccw(p1.first,p1.second,p2.first,p2.second,p4.first,p4.second);
    int temp2=ccw(p3.first,p3.second,p4.first,p4.second,p1.first,p1.second)*ccw(p3.first,p3.second,p4.first,p4.second,p2.first,p2.second);

    if(temp1==0 && temp2==0)
    {
        if(p1>p2) swap(p1,p2);
        if(p3>p4) swap(p3,p4);
        return p3<=p2 && p1<=p4;
    }
    return temp1<=0 && temp2<=0;
}
void dfs(int x,int col)
{
    //cout<<x<<" "<<col<<'\n';
    ch[x]=col;
    for(auto i:v[x])
    {
        if(ch[i]==col)
        {
            flag=1;
            return;
        }
        else if(ch[i]==0)
            dfs(i,col^3);
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=m;i++)
    {
        int a,x,y;
        cin>>a>>x>>y;
        L[i]={arr[a].first,arr[a].second,x,y};
    }
    for(int i=1;i<=m;i++)
    {
        int temp=0;
        for(int j=1;j<=m;j++)
        {
            if(i==j || (L[i].x1==L[j].x1 && L[i].y1==L[j].y1))
                continue;
            if(intersect(L[i],L[j]))
            {
                //cout<<i<<" "<<j<<'\n';
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(ch[i]==0) dfs(i,1);
    }
    if(flag) cout<<"impossible";
    else cout<<"possible";
}