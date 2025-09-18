# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int arr[200010];
void sol()
{
    queue<int> q;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    int cnt=0,num=1;
    int mx=0;
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1 && arr[i]!=arr[i-1])
        {
            if(arr[i]-1==arr[i-1])
            {
                q.push(temp);
                temp=0;
                num++;
            }
            else
            {
                mx=max(mx,cnt);
                cnt=0;
                temp=0;
                num=1;
                while(!q.empty()) q.pop();
            }
        }
        if(num>k)
        {
            num--;
            mx=max(mx,cnt);
            cnt-=q.front();
            //cout<<q.front()<<'\n';
            q.pop();
        }
        cnt++;
        temp++;
        //cout<<num<<" "<<cnt<<" "<<temp<<'\n';
    }
    cout<<max(mx,cnt)<<'\n';
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