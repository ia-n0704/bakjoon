# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s;
int main()
{
    fastio;
    stack<int> st;
    cin>>s;
    int res=0;
    int num=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(') st.push(2);
        else if(s[i]=='[') st.push(3);
        else if(s[i]==')')
        {
            if(st.empty())
            {
                cout<<0;
                return 0;
            }
            if(st.top()=='(') num*=2;
            else
            {
                cout<<0;
                return 0;
            }
            st.pop();
        }
        else
        {
            
        }
    }   
}