#include <bits/stdc++.h>
using namespace std;
int arr[300010];
int brr[300010];
int al,ar,bl,br,am,bm;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        brr[i]=min(arr[i],arr[i+1]);
    bool aflag=0,bflag=0;
    for(int i=0;i<n;i++)
    {
        int temp=n-i;
        if(temp==1)
        {
            int mx=0;
            for(int j=1;j<=n;j++)
                mx=max(mx,arr[j]);
            cout<<mx<<" ";
        }
        else
        {
            if(temp%2)
            {
                int temp=n-i-1;
                int l=temp/2,r=temp/2+n-temp;
                if(bflag==0)
                {
                    bflag=1;
                    bl=l;
                    br=r;
                    for(int j=bl;j<=br;j++)
                        bm=max(bm,brr[j]);
                }
                while(l<bl)
                    bm=max(bm,brr[--bl]);
                while(r>br)
                    bm=max(bm,brr[++br]);
                cout<<bm<<" ";
            }
            else
            {
                int temp=n-i;
                int l=temp/2,r=temp/2+1+n-temp;
                if(aflag==0)
                {
                    aflag=1;
                    al=l;
                    ar=r;
                    for(int j=al;j<=ar;j++)
                        am=max(am,arr[j]);
                }
                while(l<al)
                    am=max(am,arr[--al]);
                while(r>ar)
                    am=max(am,arr[++ar]);
                cout<<am<<" ";                
            }
        }
    }
}