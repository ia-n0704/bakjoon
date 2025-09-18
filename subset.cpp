#include <bits/stdc++.h>
using namespace std;

#define N 41
using ld=long long;
ld n,s,a[N],ans;
map <int,ld> m;

void dp(int i,int k,int e) {
    if (i==e) {
        if (e==n)
        {
            ans+=m[s-k];
            cout<<s-k<<" "<<ans<<'\n';
        }
        else m[k]++;
        return;
    }
    dp(i+1,k,e);
    dp(i+1,k+a[i],e);
}

int main() {
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>a[i];
    dp(0,0,n/2);
    for(int i=0;i<=s;i++) cout<<m[i]<<" ";
    dp(n/2,0,n);
    if (!s) ans--;
    cout<<ans;
}