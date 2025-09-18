# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define inf 1e9
int arr[300010];
pair<int,int> ri[300010],le[300010];
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
        arr[i]=s[i-1]-'0';
    le[0]={0,0};
    for(int i=1;i<=n;i++)
    {
        if(i!=1) le[i]={le[i-1].first,le[i-1].second};
        if(arr[i]==0) le[i].first++;
        else le[i].second++;
    }
    for(int i=n;i>=0;i--)
    {
        if(i!=n) ri[i]={ri[i+1].first,ri[i+1].second};
        if(arr[i]==0) ri[i].first++;
        else ri[i].second++;
    }
    int ze=0,on=0;
    int res=inf;
    vector<int> v;
    for(int i=0;i<=n;i++)
    {
        int a=i/2;
        if(i%2) a++;
        int b=(n-i)/2;
        if((n-i)%2) b++;
        if(le[i].first>=a && ri[i+1].second>=b)
        {
            if(abs(n-2*i)<abs(n-2*res))
                res=i;
        }
        if(arr[i]==1)
            on++;
        else ze++;
    }
    cout<<res<<'\n';
    for(int i=0;i<=n;i++)
    {
        le[i]={0,0};
        ri[i]={0,0};
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