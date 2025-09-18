#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n;
vector<int> v[100];
int ch[100];
void dfs(int node,int depth)
{
    cout<<node<<" "<<depth<<'\n';
    ch[node]=depth;
    if(node==2)
        return;
    for(auto i:v[node])
    {
        if(ch[i]>depth+1)
            dfs(i,depth+1);
    }
}
int main()
{
    cin>>n;
    fill(ch,ch+n+1,inf);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a; scanf("%1d",&a);
            if(a)
            {
                v[i].push_back(j);
                v[j].push_back(j);
            }
        }
    }
    dfs(1,0);
    cout<<ch[2]<<" ";
    if(ch[2]==inf) cout<<-1;
    else
        cout<<(ch[2]-1)/2+1;
}