/*#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[300010];
int q,k;
int ch[300010];
int arr[300010];
long long cnt;
long long num;
long long dfs(int a)
{
    //cout<<a<<" ";
    if(ch[a]==0)
        return ch[a]=num++;
    for(auto i:v[a])
    {
        if(ch[i]==0)
            return ch[a]=dfs(i);
    }
    return 1;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>q;
    fill(ch,ch+n+1,-1);
    while(q--)
    {
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>arr[i];
            ch[arr[i]]=0;
        }
        long long res=0;
        for(int i=0;i<k;i++)
        {
            if(ch[arr[i]]==0)
            {
                num=1;
                cnt=dfs(arr[i]);
                res+=cnt*(cnt-1)/2;
            }
        }
        for(int i=0;i<k;i++) ch[arr[i]]=0;
        cout<<res<<'\n';
    }
}*/


#include <bits/stdc++.h>
using namespace std;
int n,q,k;
int arr[300010];
int ch[300010];
vector<int> v[300010];
vector<int> t[300010];
void init(int a)
{
    
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    init(1);
}