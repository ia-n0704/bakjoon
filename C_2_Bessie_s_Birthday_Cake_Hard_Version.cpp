# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010];
void sol()
{
    int n,m,k;
    priority_queue<int> pq;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
        cin>>arr[i];
    sort(arr,arr+m);
    int num=0;
    for(int i=0;i<m;i++)
    {
        int cnt=(arr[(i+1)%m]-arr[i]+n)%n-1;
        if(cnt>=2)
        {
            num+=cnt;
            pq.push(cnt);
        }
    }
    for(int i=0;i<k;i++)
    {
        if(pq.empty()) continue;
        auto a=pq.top();
        pq.pop();
        if(a-2>=2)
        {
            pq.push(a-2);
            num-=2;
        }
        else num-=a;
    }
    int res=n-2;
    cout<<res-num<<'\n';
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