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
struct T
{
    int x,y;
};
bool compare(T a,T b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else return a.x<b.x;
}
T arr[200010];
int st[100010];
int en[100010];
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;
    sort(arr,arr+n,compare);

    //1
    int mn=200010;
    for(int i=0;i<n;i++)
    {
        st[arr[i].x]++;
        en[arr[i].y]++;
    }
    for(int i=1;i<=100000;i++)  //시작점과 끝점의 누적합
        en[i]+=en[i-1];
    for(int i=100000;i>=1;i--)
        st[i]+=st[i+1];
    for(int i=0;i<n;i++)
    {
        int l=arr[i].x;
        int r=arr[i].y;
        int num=en[l]+st[r];
        mn=min(mn,num);
    }
    cout<<n-mn<<" ";

    //2
    int mx=1;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        while(!pq.empty())
        {
            if(arr[i].x>=-pq.top())
                pq.pop();
            else break;
        }
        pq.push(-arr[i].y);
        mx=max(mx,(int)pq.size());
    }
    cout<<mx;
}