# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastio;
    string s;
    cin>>s;
    int acnt=0,bcnt=0;
    int i;
    int flag=0;
    vector<int> v;
    stack<char> st;
    for(int i=0;i<s.length();i+=2)
    {
        int cnt=0;
        while(!st.empty() && st.top()==s[i])
        {
            cnt++;
            st.pop();
        }
        if(cnt) v.push_back(cnt);
        st.push(s[i]);
    }
    if(st.empty()) cout<<"Keine Loesung";
    else
    {
        for(auto i:v)
        {
            for(int j=1;j<=i;j++) cout<<'[';
            for(int j=1;j<=i;j++) cout<<']';
        }
    }
}