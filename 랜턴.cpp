#include <bits/stdc++.h>
using namespace std;
int arr[200010];
int par[200010];
int ch[200010];
int get_par(int x)
{
    if(par[x]==x) return x;
    return par[x]=get_par(par[x]);
}
int cmp_par(int a,int b)
{
    a=get_par(a);
    b=get_par(b);
    if(a==b) return 1;
    else return 0;
}
void union_par(int a,int b)
{
    a=get_par(a);
    b=get_par(b);
    par[b]=a;
}
std::vector<int> change_lamps(std::vector<int> A, int K) {
    for(int i=0;i<A.size();i++) arr[i+1]=A[i];
    int n=A.size();
    for(int i=0;i<=n;i++) 
    {
        ch[i]=0;
        par[i]=0;
    }
    int cnt=0;
    int st=1,num=1;
    par[1]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=2;i<=n;i++)
    {
        par[i]=i;
        if(arr[i]==arr[i-1])
        {
            num++;
            union_par(i-1,i);
        }
        else
        {   
            if(st!=1)
            {
                pq.push({num,st});
                //cout<<num<<" "<<st<<'\n';
                num=1;
                cnt++;
            }
            else num=1;
            st=i;
        }
    }
    cnt+=2;
    cnt-=K;
    while(!pq.empty() && cnt>2)
    {
        auto a=pq.top(); pq.pop();
        if(ch[a.second]) continue;
        //cout<<a.second<<'\n';
        int front=a.second-1;
        int last=a.second+a.first;
        ch[front]=1;
        ch[last]=1;
        cnt-=2;
        union_par(front,a.second);
        union_par(front,last);
    }
    if(cnt>0)
    {
        int numa,numb,numc=1e9;
        numa=numb=1;
        int temp=get_par(1);
        for(int i=2;i<=n;i++)
        {
            //cout<<get_par(i)<<" ";
            if(get_par(i)!=temp) break;
            numa++;
        }
        temp=get_par(n);
        for(int i=n-1;i>=1;i--)
        {
            if(get_par(i)!=temp) break;
            numb++;
        }
        int idx;
        while(!pq.empty())
        {
            auto a=pq.top(); pq.pop();
            if(ch[a.second]) continue;
            numc=a.first;
            idx=a.second;
            break;
        }
        //cout<<numa<<" "<<numb<<" "<<numc<<'\n';
        if(cnt==1)
        {
            if(numa<=numb && numa<=numc)
                union_par(1+numa,1);
            else if(numb<=numa && numb<=numc)
                union_par(n-numb,n);
            else
            {
                union_par(idx-1,idx);
                union_par(idx-1,idx+numc);
            }
        }
        else if(cnt==2)
        {
            if(numa+numb<numc)
            {
                union_par(1+numa,1);
                union_par(n-numb,n);
            }
            else
            {
                union_par(idx-1,idx);
                union_par(idx,idx+numc);
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++)
        ans.push_back(arr[get_par(i)]);
	return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        vector<int> v;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%1d",&a); v.push_back(a);
        }
        vector<int> ans=change_lamps(v,k);
        for(auto i:ans) cout<<i;
        cout<<'\n';        
    }
}
