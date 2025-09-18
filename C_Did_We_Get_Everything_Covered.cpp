# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    vector<char> ans;
    cin>>s;
    vector<int> idx[30];
    for(int i=0;i<m;i++)
    {
        idx[s[i]-'a'].push_back(i+1);
    }
    for(int i=0;i<k;i++)
        idx[i].push_back(m+1);
    int temp=0;
    int alpha;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int mx=0;
        for(int j=0;j<k;j++)
        {
            int num=lower_bound(idx[j].begin(),idx[j].end(),temp)-idx[j].begin();
            //cout<<j<<" "<<idx[j][num]<<'\n';
            if(mx<idx[j][num])
            {
                alpha=j;
                mx=idx[j][num];
            }
        }
        ans.push_back(alpha+'a');
        if(mx==m+1)
        {
            flag=1;
            for(int r=i+1;r<n;r++)
                ans.push_back(alpha+'a');
            break;
        }
        temp=mx+1;
    }
    if(flag)
    {
        cout<<"NO\n";
        for(auto i:ans) cout<<i;
        cout<<'\n';
    }
    else cout<<"YES\n";
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