# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        arr[i]={a,i};
    }
    sort(arr+1,arr+n+1);
    reverse(arr+1,arr+n+1);
    set<int> s;
    s.insert(arr[1].second);
    for(int i=2;i<=n;i++)
    {
        auto idx=s.lower_bound(arr[i].second);
        //cout<<*idx<<'\n';
        if(idx!=s.end())
        {
            if(abs((*idx)-arr[i].second)<=2)
            {
                cout<<arr[i].first<<'\n';
                return;
            }
        }
        if(idx!=s.begin())
        {
            --idx;
            if(abs((*idx)-arr[i].second)<=2)
            {
                cout<<arr[i].first<<'\n';
                return;
            }
        }
        s.insert(arr[i].second);
    }
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