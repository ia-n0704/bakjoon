# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l=0,r=s.length()-1;
        vector<pair<int,int>> v;
        int temp=0;
        int flag=0;
        while(!flag && l<r)
        {
            if(s[l]==s[r]) 
            {
                l++;
                r--;
                continue;
            }
            if(s[l+1]==s[r])
            {
                v.push_back({l+1,r});
                flag=1;
            }
            if(s[l]==s[r-1])
            {
                flag=1;
                v.push_back({l,r-1});
            }
            if(!flag)
            {
                temp=1;
                cout<<2<<'\n';
                break;                
            }
        }
        if(temp) continue;
        if(v.size()==0)
        {
            cout<<0<<'\n';
            continue;
        }
        int num=2;
        for(auto i:v)
        {
            int l=i.first,r=i.second;
            //cout<<l<<' '<<r<<'\n';
            int flag=0;
            while(l<r)
            {
                if(s[l]==s[r]) 
                {
                    l++;
                    r--;
                    continue;
                }
                if(s[l+1]==s[r])
                {
                    flag=1;
                    break;
                }
                else if(s[l]==s[r-1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                num=1;
                break;
            }
        }
        cout<<num<<'\n';
    }
}