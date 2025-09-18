#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c;
ll res;
struct T
{
    ll x,y;
}arr[100010];
vector <T> v;
ll ccw(T a, T b, T c)
{
    return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}
bool compare(T a, T b)
{
    if(a.x==b.x)
        return a.x<b.x;
    else
        return a.y<b.y;
}
ll distance(T a, T b)
{
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}
bool compare2(T a, T b)
{
    ll cc(ccw(arr[1],a,b));
    if(cc<0)
        return 0;
    else if(cc>0)
        return 1;
    else
    {
        if(distance(arr[1],a)<distance(arr[1],b))
            return 1;
        else
            return 0;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll i,j;
    cin>>c;
    res=0;
    for(i=1;i<=c;i++)
        cin>>arr[i].x>>arr[i].y;
    sort(arr+1,arr+c+1,compare);
    sort(arr+1,arr+c+1,compare2);
    v.push_back(arr[1]);
    v.push_back(arr[2]);
    for(i=3;i<=c;i++)
    {
        while(v.size()>=2 && ccw(v[v.size()-2],v.back(),arr[i])<=0)
            v.pop_back();
        v.push_back(arr[i]);
    }
    int idx=1;
    for(i=0;i<v.size();i++)
    {
        ll temp=0;
        while(idx<=i || distance(v[i],v[idx%v.size()])>temp)
        {
            temp=distance(v[i],v[idx%v.size()]);
            res=max(res,temp);
            idx++;
        }
    }
    printf("%f",sqrt(res));
}
