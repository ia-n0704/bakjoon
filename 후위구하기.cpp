/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int pre[1000010];
int in[1000010];
int idx[1000010];
int cnt=1;
int arr[1000010][2];
void go(int l,int r,int par,int cmp)
{
    if(l>r) return;
    //cout<<l<<" "<<r<<" "<<par<<" "<<cmp<<'\n';
    int temp=pre[++cnt];
    arr[par][cmp]=temp;
    if(l==r)
        return;
    go(l,idx[temp]-1,temp,0);
    go(idx[temp]+1,r,temp,1);
}
void dfs3(int x)
{
    if(arr[x][0]) dfs3(arr[x][0]);
    if(arr[x][1]) dfs3(arr[x][1]);
    cout<<x<<' ';
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++)
    {
        cin>>in[i];
        idx[in[i]]=i;
    }
    go(1,idx[pre[1]]-1,1,0);
    go(idx[pre[1]]+1,n,1,1);
    dfs3(pre[1]);
}*/

#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int b[1000010];
void tree(int mid,int l,int r)
{
    for(int i=l;i<r;i++)
    {
        if(a[mid]==b[i])
        {
            tree(mid+1,l,i);
            tree(mid+i+1-l,i+1,r);
            printf("%d ",a[mid]);
            break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    tree(0,0,n);
}