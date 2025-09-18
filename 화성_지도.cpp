#include<bits/stdc++.h>
using namespace std;
struct line
{
    int x,y1,y2;
    int num;
};
int n;
vector<line> v;
int cnt[300010];
int seg[300010];
int mx;
bool compare(line a,line b)
{
    return a.x<b.x;
}
void update(int v,int st,int en, int l,int r,int a)
{
    if(st>r || en<l) return;
    if(l<=st && r>=en)
        cnt[v]+=a;
    else
    {
        int mid=(st+en)/2;
        update(v*2,st,mid,l,r,a);
        update(v*2+1,mid+1,en,l,r,a);        
    }
    seg[v]=seg[v*2]+seg[v*2+1];
    if(cnt[v]>0)
    {
        seg[v]=en-st+1;
        return;
    }
    if(st==en)
    {
        seg[v]=0;
        return;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back({a,b+1,d+1,1});
        v.push_back({c,b+1,d+1,-1});
        mx=max(mx,max(b,d)+1);
    }
    sort(v.begin(),v.end(),compare);
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        if(i!=0)
            res+=(v[i].x-v[i-1].x)*seg[1];
        update(1,1,mx,v[i].y1,v[i].y2-1,v[i].num);
    }
    cout<<res;
}