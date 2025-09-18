#include <bits/stdc++.h>
using namespace std;
int n,m;
int finish[100010];
int ch[100010];
int scc[100010];
vector <int> v[100010];
int num;
stack <int> s;
int scc_count;
int SCC(int a)
{
    ch[a]=++num;
    int p=num;
    s.push(a);
    for(int i=0;i<v[a].size();i++)
    {
        int b=v[a][i];
        if(ch[b]==0) p=min(p,SCC(b));
        else if(finish[b]==0) p=min(p,ch[b]);
    }

    if(p==ch[a])
    {
        scc_count++;
        while(1)
        {

            int temp=s.top();
            //printf("%d | %d\n",temp,scc_count);
            finish[temp]=1;
            s.pop();
            scc[temp]=scc_count;
            if(temp==a)
                break;
        }
    }

    return p;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c,na,nb,nc;
        char aa,bb,cc;
        cin>>a>>aa>>b>>bb>>c>>cc;
        a--,b--,c--;
        if(aa=='R')
        {
            na=a*2+1;
            a*=2;
        }
        else
        {
            na=a*2;
            a=a*2+1;
        }
        if(bb=='R')
        {
            nb=b*2+1;
            b*=2;
        }
        else
        {
            nb=b*2;
            b=b*2+1;
        }
        if(cc=='R')
        {
            nc=c*2+1;
            c*=2;
        }
        else
        {
            nc=c*2;
            c=c*2+1;
        }
        v[na].push_back(b);
        v[na].push_back(c);
        v[nb].push_back(a);
        v[nb].push_back(c);
        v[nc].push_back(a);
        v[nc].push_back(b);
    }
    for(int i=0;i<n*2;i++)
        if(!ch[i]) SCC(i);
    vector<char> res;
    for(int i=0;i<n;i++)
    {
        if(scc[i*2]==scc[i*2+1])
        {
            cout<<-1;
            return 0;
        }
        if(scc[i*2]<scc[i*2+1]) res.push_back('R');
        else res.push_back('B');
    }
    for(auto i:res) cout<<i;
}