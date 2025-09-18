# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,k;
string s;
vector<int> v;
vector<pair<int,int>> ans;
int ch[500010];
int cnt;
int flag;
int main()
{
    fastio;
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]!=s[i-1]) v.push_back(i+1);
    }
    if(v.size()==0)
    {
        cout<<0;
        return 0;
    }
    int idx=v.size()/2;
    for(int i=0;i<v.size()/2;i++)
    {
        while(idx<v.size() && v[idx]-v[i]<k) idx++;
        if(idx<v.size())
        {
            ch[i]=1;
            ch[idx]=1;
            cnt++;
            ans.push_back({v[i],v[idx]-1});
            idx++;
        }
    }
    vector<int> v2;
    for(int i=0;i<v.size();i++)
    {
        if(ch[i]==0) v2.push_back(v[i]);
    }
    for(int i=0;i<v2.size();i++)
    {
        if(v2[i]-1>=k)
        {
            cnt++;
            ans.push_back({1,v2[i]-1});
        }
        else if(n-v2[i]+1>=k)
        {
            cnt++;
            ans.push_back({v2[i],n});
        }
        else flag=1;
    }
    if(flag) cout<<-1;
    else
    {
        cout<<cnt<<'\n';
        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<'\n';
    }
}


/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> v;
vector <pair<int, int> > pr;
int ans = 0;
bool a[500001] = {};
int main() {
   int n, k;
   string s;

   cin >> n >> k;
   cin >> s;
   int str = s.size();
   for (int i = 1; i < str; i++) {
      if (s[i - 1] != s[i])
      {
        cout<<i+1<<" ";
        v.push_back(i + 1);
      }
   }
   int m = v.size(), p = v.size() / 2;
   if (!m) {
      cout << "0";
      return 0;
   }
   for (int i = 0; i < m; i++) if (!a[i]) {
      while (p < m) {
         if (!a[p] && v[p] - v[i] >= k) break;
         p += 1;
      }
      if (p == m) break;
      a[i] = 1;
      a[p] = 1;
      pr.push_back({ v[i], v[p] - 1 });
      ans += 1;
   }
   for (int i = 0; i < m; i++) if (!a[i]) {
      if (v[i] - 1 >= k) pr.push_back({ 1, v[i] - 1 });
      else if (n - v[i] + 1 >= k) pr.push_back({ v[i], n });
      else {
         cout << "-1\n";
         return 0;
      }
      ans += 1;
   }
   cout << ans << "\n";
   int ps = pr.size();
   for (int i = 0; i < ps; i++) {
      pair<int, int> t = pr[i];
      cout << t.first << " " << t.second << "\n";
   }
}*/