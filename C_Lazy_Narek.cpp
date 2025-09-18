# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string s[10010];
pair<pair<int,int>,pair<int,int>> arr[10][10010];
int point[10];
int ch[10010];
string t="narek";
void sol()
{
    cin>>n>>m;
    fill(ch,ch+n+1,0);
    fill(point,point+6,0);
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            int cnt=0;
            int trash=0;
            int cur=j;
            for(int k=0;k<m;k++)
            {
                if(t[cur]==s[i][k])
                {
                    cnt++;
                    cur++;
                    cur%=5;
                }
                else if(s[i][k]!='n' && s[i][k]!='a' && s[i][k]!='e' && s[i][k]!='r' && s[i][k]!='k')
                    trash++;
            }
            arr[j][i]={{-(cnt-(m-cnt-trash)),cnt},{i,m-cnt-trash}};
        }
    }
    for(int i=0;i<5;i++)
        stable_sort(arr[i],arr[i]+n);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j].first.first*=-1;
    }
    int success=0,fail=0;
    int cur=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        while(ch[arr[cur][point[cur]].second.first]) point[cur]++;
        //cout<<"| "<<arr[cur][point[cur]].first.first<<" "<<arr[cur][point[cur]].second<<'\n';
        fail+=arr[cur][point[cur]].second.second;
        ch[arr[cur][point[cur]].second.first]=1;
        cur+=arr[cur][point[cur]].first.second;
        success+=cur/5;
        cur%=5;
        int num=success*5-fail;
        res=max(res,num);
        //cout<<success<<" "<<fail<<'\n';
    }
    cout<<res<<'\n';
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