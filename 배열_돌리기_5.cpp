# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,r;
int arr[101][101],brr[101][101];
int ans[101][101];
pair<pair<pll,pll>,pair<pll,pll>> s[5];
void five()
{
    swap(s[1],s[2]);
    swap(s[3],s[4]);
    swap(s[1],s[4]);
}
void six()
{
    swap(s[1],s[3]);
    swap(s[2],s[4]);
    swap(s[1],s[4]);
}
int main()
{
    fastio;
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    }
    int nn=n/2,mm=m/2;
    s[1]={{{1,1},{1,mm}},{{nn,1},{nn,mm}}};
    s[2]={{{1,mm+1},{1,m}},{{nn,mm+1},{nn,m}}};
    s[3]={{{nn+1,1},{nn+1,mm}},{{n,1},{n,mm}}};
    s[4]={{{nn+1,mm+1},{nn+1,m}},{{n,mm+1},{n,m}}};
    if(n<=10 || m<=1)
    {
        while(r--)
        {
            int a;
            cin>>a;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    brr[i][j]=arr[i][j];
            if(a==1)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        arr[n-i+1][j]=brr[i][j];
                }
            }
            else if(a==2)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        arr[i][m-j+1]=brr[i][j];
                }
            }
            else if(a==3)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        arr[j][n-i+1]=brr[i][j];
                }
                swap(n,m);
            }
            else if(a==4)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        arr[m-j+1][i]=brr[i][j];
                }
                swap(n,m);
            }
            else if(a==5)
            {
                for(int i=1;i<=n/2;i++)
                    for(int j=1;j<=m/2;j++)
                        brr[i][j]=arr[i][j];
                
                for(int i=n/2+1;i<=n;i++)
                    for(int j=1;j<=m/2;j++)
                        arr[i-n/2][j]=arr[i][j];

                for(int i=n/2+1;i<=n;i++)
                    for(int j=m/2+1;j<=m;j++)
                        arr[i][j-m/2]=arr[i][j];

                for(int i=1;i<=n/2;i++)
                    for(int j=m/2+1;j<=m;j++)
                        arr[i+n/2][j]=arr[i][j];
                
                for(int i=1;i<=n/2;i++)
                    for(int j=1;j<=m/2;j++)
                        arr[i][j+m/2]=brr[i][j];
            }
            else if(a==6)
            {
                for(int i=1;i<=n/2;i++)
                    for(int j=1;j<=m/2;j++)
                        brr[i][j]=arr[i][j];
                
                for(int i=1;i<=n/2;i++)
                    for(int j=m/2+1;j<=m;j++)
                        arr[i][j-m/2]=arr[i][j];

                for(int i=n/2+1;i<=n;i++)
                    for(int j=m/2+1;j<=m;j++)
                        arr[i-n/2][j]=arr[i][j];

                for(int i=n/2+1;i<=n;i++)
                    for(int j=1;j<=m/2;j++)
                        arr[i][j+m/2]=arr[i][j];
                
                for(int i=1;i<=n/2;i++)
                    for(int j=1;j<=m/2;j++)
                        arr[i+n/2][j]=brr[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<arr[i][j]<<" ";
            cout<<'\n';
        }
        return 0;
    }
    while(r--)
    {
        int a; cin>>a;
        if(a==1)
        {
            for(int i=1;i<=4;i++)
            {
                swap(s[i].first.first,s[i].second.first);
                swap(s[i].first.second,s[i].second.second);
            }
            swap(s[1],s[3]);
            swap(s[2],s[4]);            
        }
        else if(a==2)
        {
            for(int i=1;i<=4;i++)
            {
                swap(s[i].first.first,s[i].first.second);
                swap(s[i].second.first,s[i].second.second);
            }
            swap(s[1],s[2]);
            swap(s[3],s[4]);
        }
        else if(a==3)
        {
            for(int i=1;i<=4;i++)
            {
                swap(s[i].first.first,s[i].first.second);
                swap(s[i].second.first,s[i].second.second);
                swap(s[i].first.first,s[i].second.second);
            }
            five();
        }
        else if(a==4)
        {
            for(int i=1;i<=4;i++)
            {
                swap(s[i].first.first,s[i].second.first);
                swap(s[i].first.second,s[i].second.second);
                swap(s[i].first.first,s[i].second.second);
            }
            six();
        }
        else if(a==5) five();
        else if(a==6) six();
    }
    /*for(int i=1;i<=4;i++)
    {
        cout<<s[i].first.first.first<<" "<<s[i].first.first.second<<'\n';
        cout<<s[i].first.second.first<<" "<<s[i].first.second.second<<'\n';
        cout<<s[i].second.first.first<<" "<<s[i].second.first.second<<'\n';
        cout<<s[i].second.second.first<<" "<<s[i].second.second.second<<'\n';
        cout<<'\n';
    }*/
    int x=1,y=1;
    int stx,enx,sty,eny;
    int temp;
    int tx,ty;
    for(int i=1;i<=4;i++)
    {
        int flag=0;
        if(i==2)
            x=1,y=ty+1;
        if(i==3)
            x=tx+1,y=1;
        if(i==4)
            x=tx+1,y=ty+1;
        if(s[i].first.first.first==s[i].second.first.first)
        {
            stx=s[i].first.first.second;
            enx=s[i].second.first.second;
        }
        else
        {
            stx=s[i].first.first.first;
            enx=s[i].second.first.first;
            flag=1;
        }        
        if(s[i].first.first.first==s[i].first.second.first)
        {
            sty=s[i].first.first.second;
            eny=s[i].first.second.second;
        }
        else
        {
            sty=s[i].first.first.first;
            eny=s[i].first.second.first;
        }     
        //cout<<i<<" - "<<stx<<" "<<enx<<" | "<<sty<<" "<<eny<<" "<<flag<<'\n';   
        if(stx<enx)
        {
            for(int j=stx;j<=enx;j++)
            {
                if(sty<eny)
                {
                    for(int k=sty;k<=eny;k++)
                    {
                        if(flag)
                            ans[x][y++]=arr[j][k];
                        else
                            ans[x][y++]=arr[k][j];
                    }
                }
                else
                {
                    for(int k=sty;k>=eny;k--)
                    {
                        if(flag)
                            ans[x][y++]=arr[j][k];
                        else
                            ans[x][y++]=arr[k][j];
                    }
                }
                x++;
                if(j!=enx) y-=max(sty,eny)-min(sty,eny)+1;
            }
        }
        else
        {
            for(int j=stx;j>=enx;j--)
            {
                if(sty<eny)
                {
                    for(int k=sty;k<=eny;k++)
                    {
                        if(flag)
                            ans[x][y++]=arr[j][k];
                        else
                            ans[x][y++]=arr[k][j];
                    }
                }
                else
                {
                    for(int k=sty;k>=eny;k--)
                    {
                        if(flag)
                            ans[x][y++]=arr[j][k];
                        else
                            ans[x][y++]=arr[k][j];
                    }
                }
                x++;
                if(j!=enx) y-=max(sty,eny)-min(sty,eny)+1;
            }
        }
        if(i==1) 
        {
            tx=x-1,ty=y-1;
        }
    }
    for(int i=1;i<x;i++)
    {
        for(int j=1;j<y;j++)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}