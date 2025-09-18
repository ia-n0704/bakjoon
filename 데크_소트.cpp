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
pair<int,int> brr[1010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i].first;
        brr[i].second=-i;
    }
    stable_sort(brr+1,brr+n+1);
    vector<pair<int,int>> arr;
    arr.push_back({0,0});
    for(int i=1;i<=n;i++)
        if(i==1 || brr[i-1].first!=brr[i].first) arr.push_back(brr[i]);
    for(int i=1;i<arr.size();i++)
        cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    cout<<'\n';
    int flag=0,last=0;
    int res=1;
    arr[1].second*=-1;
    for(int i=2;i<arr.size();i++)
    {
        //cout<<last<<" "<<flag<<'\n';
        arr[i].second*=-1;
        if(flag==0)
        {
            if(last==0)
            {
                if(arr[i].second>arr[i-1].second)
                    last=1;
                else last=2;
            }
            else
            {
                if(arr[i].second>arr[i-1].second && last==2)
                {
                    flag=1;
                    last=1;
                }
                else if(arr[i].second<arr[i-1].second && last==1)
                {
                    res++;
                    //cout<<i<<'\n';
                    flag=last=0;
                }
            }
        }
        else
        {
            if(arr[i].second>arr[i-1].second && last==2)
            {
                res++;
                //cout<<i<<'\n';
                flag=last=0;
            }
            else if(arr[i].second<arr[i-1].second && last==1)
            {
                res++;
                //cout<<i<<'\n';
                flag=last=0;
            }
        }
    }
    cout<<res;
}