# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    string s;
    int n;
    cin>>n>>s;
    int cnt=0;
    for(int i=0;i<n;i++) if(s[i]==')') cnt++;
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') num++;
        else if(s[i]==')') num--;
        else if(s[i]=='_')
        {
            if(num && cnt<n/2)
            {
                cnt++;
                num--;
                s[i]=')';
            }
            else 
            {
                s[i]='(';
                num++;
            }
        }
    }
    stack<int> st;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') st.push(i);
        else res+=i-st.top(),st.pop();
    }
    cout<<res<<'\n';
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