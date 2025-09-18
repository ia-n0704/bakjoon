# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int ch[150];
int num[150];
void sol()
{
    vector<char> v;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(ch[s[i]-'0']==0) 
        {
            ch[s[i]-'0']=1;
            v.push_back(s[i]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        num[v[i]-'0']=v[v.size()-i-1]-'0';
    }
    for(int i=0;i<s.length();i++)
    {
        if(ch[s[i]-'0']==1) s[i]=num[s[i]-'0']+'0';
    }
    cout<<s<<'\n';
    fill(num,num+140,0);
    fill(ch,ch+140,0);
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