#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define sz 2010
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,k;
int arr[sz][sz];
int rowsum[sz][sz],colsum[sz][sz];
int len[sz][sz];
int res=1e9;
int main()
{
    fastio;
    cin>>k>>m>>n;       //입력
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
        

    //#1 가로 방향
    for(int i=1;i<=n;i++)       //전처리
    {
        for(int j=1;j<=m;j++)
        {
            rowsum[i][j]=rowsum[i][j-1]+arr[i][j];
            colsum[i][j]=colsum[i-1][j]+arr[i][j];
        }
        rowsum[i][m+1]=rowsum[i][m];
    }
    for(int i=1;i<=m;i++)
        colsum[n+1][i]=colsum[n][i];
    for(int i=1;i<=n;i++)
    {
        int l=0,r=1;
        while(l<=m)
        {
            if(r>m || rowsum[i][r]-rowsum[i][l]>k)
            {
                len[i][l]=r;
                l++;
            }
            else
                r++;
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<len[i][j]<<" ";
        }
        cout<<'\n';
    }*/
        
    for(int i=0;i<=m;i++)       //sol
    {
        int l=i,r=0;
        for(int j=1;j<=n;j++)
            r=max(r,m-len[j][l]+1);
        int h=n-1;
        int num=l+r+h;
        //cout<<l<<" "<<r<<" "<<num+1;
        int st=1,en=m,top=1,bot=n;
        for(int j=1;j<=num;j++)
        {
            if(l)
            {
                if(colsum[bot][st]-colsum[top-1][st]<=k)
                {
                    l--;
                    st++;
                    continue;
                }
            }
            if(r)
            {
                if(colsum[bot][en]-colsum[top-1][en]<=k)
                {
                    r--;
                    en--;
                    continue;
                }
            }
            if(rowsum[top][en]-rowsum[top][st-1]<=k)
            {
                h--;
                top++;
                continue;
            }
            if(rowsum[bot][en]-rowsum[bot][st-1]<=k)
            {
                h--;
                bot--;
                continue;
            }
        }
        //cout<<" | "<<h<<'\n';
        if(!h && rowsum[top][en]-rowsum[top][st-1]<=k)
            res=min(res,num+1);
    }
    for(int i=1;i<=n;i++)
    {
        fill(rowsum[i],rowsum[i]+m+1,0);
        fill(colsum[i],colsum[i]+m+1,0);
        fill(len[i],len[i]+m+1,0);
    }

    //#1 세로 방향
    int temp=m;
    m=n;
    n=temp;
    for(int i=1;i<=n;i++)       //전처리
    {
        for(int j=1;j<=m;j++)
        {
            rowsum[i][j]=rowsum[i][j-1]+arr[j][n-i+1];
            colsum[i][j]=colsum[i-1][j]+arr[j][n-i+1];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int l=0,r=1;
        while(l<=m)
        {
            if(r>m || rowsum[i][r]-rowsum[i][l]>k)
            {
                len[i][l]=r;
                l++;
            }
            else
                r++;
        }
    }

    for(int i=0;i<=m;i++)       //sol
    {
        int l=i,r=0;
        for(int j=1;j<=n;j++)
            r=max(r,m-len[j][l]+1);
            //cout<<l<<" "<<r<<'\n';
        int h=n-1;
        int num=l+r+h;
        int st=1,en=m,top=1,bot=n;
        for(int j=1;j<=num;j++)
        {
            
            if(l)
            {
                if(colsum[bot][st]-colsum[top-1][st]<=k)
                {
                    l--;
                    st++;
                    continue;
                }
            }
            if(r)
            {
                if(colsum[bot][en]-colsum[top-1][en]<=k)
                {
                    r--;
                    en--;
                    continue;
                }
            }
            if(rowsum[top][en]-rowsum[top][st-1]<=k)
            {
                h--;
                top++;
                continue;
            }
            if(rowsum[bot][en]-rowsum[bot][st-1]<=k)
            {
                h--;
                bot--;
                continue;
            }
        }
        if(!h && rowsum[top][en]-rowsum[top][st-1]<=k)
            res=min(res,num+1);
    }
    cout<<res;
}