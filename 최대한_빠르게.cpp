#include <bits/stdc++.h>
using namespace std;
int X[10]={-1,0,1,0};
int Y[10]={0,1,0,-1};
char dir[10]={'W','D','S','A'};
pair<char,int> ans[100][100][50];
int mn[100][100][50];
int h,w,k;
string s[100];
pair<int,int> st,en;
int main()
{
    cin>>h>>w>>k;
    for(int i=0;i<h;i++)
    {
        cin>>s[i];
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='S')
                st={i,j};
            if(s[i][j]=='T')
                en={i,j};
            for(int r=0;r<=k+1;r++)
                mn[i][j][r]=2e9;
        }
    }
    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,1},st});
    mn[st.first][st.second][1]=0;
    while(!q.empty())
    {
        auto a=q.top();
        //cout<<a.first.first<<" "<<a.first.second<<" "<<a.second.first<<" "<<a.second.second<<'\n';
        q.pop();
        if(a.second==en)
            continue;
        pair<int,int> cur=a.second;
        int co=-a.first.first;
        int boost=a.first.second;
        for(int i=1;i<=boost;i++)
        {
            for(int j=0;j<4;j++)
            {
                int nx=cur.first+X[j]*i;
                int ny=cur.second+Y[j]*i;
                int nx_co=co+1;
                int nx_boost=boost;
                if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                int f=0;
                if(X[j]==0)
                {
                    for(int r=min(ny,cur.second);r<=max(cur.second,ny);r++)
                        if(s[nx][r]=='#') f=1;                 
                }
                else
                {
                    for(int r=min(nx,cur.first);r<=max(cur.first,nx);r++)
                        if(s[r][ny]=='#') f=1;  
                }
                if(f) continue;
                if(s[nx][ny]=='@')
                    nx_boost++;
                if(mn[nx][ny][nx_boost]>nx_co)
                {
                    mn[nx][ny][nx_boost]=nx_co;
                    ans[nx][ny][nx_boost]={dir[j],i};
                    q.push({{-nx_co,nx_boost},{nx,ny}});
                }
            }
        }
    }
    pair<pair<int,int>,pair<int,int>> cur={{2e9,2e9},en};
    for(int i=0;i<=k+1;i++)
    {
        cout<<mn[en.first][en.second][i]<<' ';
        if(cur.first.first>mn[en.first][en.second][i])
            cur.first={mn[en.first][en.second][i],i};
    }
    cout<<mn[29][1][1];
    vector<pair<int,int>> res;
    /*while(1)
    {
        if(cur.second==st)
            break;
        int idx,flag=0;
        pair<int,int> temp=ans[cur.second.first][cur.second.second][cur.first.second];
        pair<int,int> loc=cur.second;
        int cnt=cur.first.second;
        if(s[loc.first][loc.second]=='@') flag=1;
        if(ans[loc.first][loc.second][cnt].first=='W')
            idx=0;
        if(ans[loc.first][loc.second][cnt].first=='D')
            idx=1;
        if(ans[loc.first][loc.second][cnt].first=='S')
            idx=2;
        if(ans[loc.first][loc.second][cnt].first=='A')
            idx=3;
        pair<int,int> nx_loc={loc.first+X[idx]*(cnt-flag),loc.second+Y[idx]*(cnt-flag)};
        cur.second=nx_loc;
        cur.first.first=cnt-flag;
        res.push_back({dir[idx],cur.first.first});
    }*/
    reverse(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto i:res)
        cout<<i.first<<" "<<i.second<<'\n';
}