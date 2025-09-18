# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010],brr[200010],crr[200010];
ll dpa[200010],dpb[200010],dpc[200010];
ll suma[200010],sumb[200010],sumc[200010];
void sol()
{
    int n;
    ll tot=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>brr[i];
    for(int i=1;i<=n;i++) cin>>crr[i];
    for(int i=1;i<=n;i++) suma[i]=suma[i-1]+arr[i];
    for(int i=1;i<=n;i++) sumb[i]=sumb[i-1]+brr[i];
    for(int i=1;i<=n;i++) sumc[i]=sumc[i-1]+crr[i];
    for(int i=1;i<=n;i++) tot+=arr[i];
    ll num=tot/3;
    if(tot%3) num++;
    int l=1,r=1;
    while(1)
    {
        if(l>n || r>n) break;
        if(suma[r]-suma[l-1]>=num)
        {
            dpa[l]=r;
            l++;
            continue;
        }
        r++;
    }
    l=1,r=1;
    while(1)
    {
        if(l>n || r>n) break;
        if(sumb[r]-sumb[l-1]>=num)
        {
            dpb[l]=r;
            l++;
            continue;
        }
        r++;
    }
    l=1,r=1;
    while(1)
    {
        if(l>n || r>n) break;
        if(sumc[r]-sumc[l-1]>=num)
        {
            dpc[l]=r;
            l++;
            continue;
        }
        r++;
    }
    int flag=0;
    int al,ar,bl,br,cl,cr;
    //arr->brr->crr
    int tempa=dpa[1];
    if(tempa!=0)
    {
        al=1,ar=tempa;
        int tempb=dpb[tempa+1];
        if(tempb!=0)
        {
            bl=tempa+1,br=tempb;
            int tempc=dpc[tempb+1];
            if(tempc!=0)
            {
                cl=tempb+1,cr=n;
                cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr<<'\n';
                flag=1;
            }
        }        
    }
    //arr->crr->brr
    tempa=dpa[1];
    if(!flag && tempa!=0)
    {
        al=1,ar=tempa;
        int tempb=dpc[tempa+1];
        if(tempb!=0)
        {
            cl=tempa+1,cr=tempb;
            int tempc=dpb[tempb+1];
            if(tempc!=0)
            {
                bl=tempb+1,br=n;
                cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr<<'\n';
                flag=1;
            }
        }        
    }
    //brr->arr->crr
    tempa=dpb[1];
    if(!flag && tempa!=0)
    {
        bl=1,br=tempa;
        int tempb=dpa[tempa+1];
        if(tempb!=0)
        {
            al=tempa+1,ar=tempb;
            int tempc=dpc[tempb+1];
            if(tempc!=0)
            {
                cl=tempb+1,cr=n;
                cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr<<'\n';
                flag=1;
            }
        }        
    }
    //brr->crr->arr
    tempa=dpb[1];
    if(!flag && tempa!=0)
    {
        bl=1,br=tempa;
        int tempb=dpc[tempa+1];
        if(tempb!=0)
        {
            cl=tempa+1,cr=tempb;
            int tempc=dpa[tempb+1];
            if(tempc!=0)
            {
                al=tempb+1,ar=n;
                cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr<<'\n';
                flag=1;
            }
        }        
    }
    //crr->arr->brr
    tempa=dpc[1];
    if(!flag && tempa!=0)
    {
        cl=1,cr=tempa;
        int tempb=dpa[tempa+1];
        if(tempb!=0)
        {
            al=tempa+1,ar=tempb;
            int tempc=dpb[tempb+1];
            if(tempc!=0)
            {
                bl=tempb+1,br=n;
                cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr<<'\n';
                flag=1;
            }
        }        
    }
    //crr->brr->arr
    tempa=dpc[1];
    if(!flag && tempa!=0)
    {
        cl=1,cr=tempa;
        int tempb=dpb[tempa+1];
        if(tempb!=0)
        {
            bl=tempa+1,br=tempb;
            int tempc=dpa[tempb+1];
            if(tempc!=0)
            {
                al=tempb+1,ar=n;
                cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr<<'\n';
                flag=1;
            }
        }        
    }
    if(flag==0) cout<<-1<<'\n';
    for(int i=0;i<=n+2;i++)
    {
        suma[i]=0;
        sumb[i]=0;
        sumc[i]=0;
        dpa[i]=0;
        dpb[i]=0;
        dpc[i]=0;
    }
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