#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200010];
int ch[200010];
int num[200010];
int indeg[200010];
vector<int> v;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        indeg[arr[i]]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            num[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ch[cur]=1;
        indeg[arr[cur]]--;
        if(indeg[arr[cur]]==0)
        {
            num[arr[cur]]=max(num[arr[cur]],num[cur]+1);
            q.push(arr[cur]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            
            int cur=i;
            while(1)
            {
                if(ch[cur]) break;
                ch[cur]=1;
                v.push_back(cur);
                cur=arr[cur];
            }
            v.clear();
        }
    }
}