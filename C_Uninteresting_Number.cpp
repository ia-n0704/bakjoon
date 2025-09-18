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
    cin>>s;
    int sum=0,two=0,three=0;
    for(int i=0;i<s.length();i++)
    {
        int a=s[i]-'0';
        sum+=a;
        if(a==2) two++;
        else if(a==3) three++;
    }
    int num=9-sum%9;
    if(num==9)
    {
        cout<<"YES\n";
        return;
    }
    vector<int> v,v2,ans;
    for(int i=1;i<=10;i++)
    {
        if(two==0) break;
        v.push_back((2*i)%9);
        ans.push_back((2*i)%9);
        two--;
    }
    for(int i=1;i<=2;i++)
    {
        if(three==0) break;
        v2.push_back((6*i)%9);
        ans.push_back((6*i)%9);
        three--;
    }
    for(auto i:v)
    {
        for(auto j:v2)
        {
            ans.push_back((i+j)%9);
        }
    }
    for(auto i:ans)
    {
        if(i==num)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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