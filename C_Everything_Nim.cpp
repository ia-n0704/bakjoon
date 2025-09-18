# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    set<int> s;
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(s.count(a)==0)
        {
            s.insert(a);
            v.push_back(a);
        }
    }
    sort(v.begin(),v.end());
    if(v[0]!=1) 
    {
        cout<<"Alice\n";
        return;
    }
    int i;
    for(i=1;i<v.size();i++)
    {
        if(v[i]-1!=v[i-1])
            break;
    }
    if(i==v.size())
        i++;
    if(i%2)
        cout<<"Bob\n";
    else cout<<"Alice\n";
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