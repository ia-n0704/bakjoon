# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200010];
int arr[1000],brr[1000];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>s[i];
    string t;
    cin>>t;
    for(int i=1;i<=2*n;i++)
    {
        for(int j=0;j<s[i].length();j++)
        {
            arr[s[i][j]-'a']++;
        }
    }
    for(int i=0;i<t.length();i++)   
        brr[t[i]-'a']++;
    for(int i=0;i<='z'-'a';i++)
    {
        //cout<<arr[i]<<'\n';
        if(arr[i]%2!=brr[i]%2) cout<<char(i+'a')<<'\n';
        arr[i]=brr[i]=0;
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