# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct T
{  
    int f,g;
    int lnum,rnum;
    int lcnt,rcnt;
    int len;
};
int n,q;
int arr[200010];
T seg[800010];
T merge(T a,T b)
{
    T res;
    res.len=a.len+b.len;
    res.f=max(a.f,b.f);
    res.g=max(a.g,b.g);
    res.lnum=a.lnum;
    res.rnum=b.rnum;
    res.lcnt=a.lcnt;
    res.rcnt=b.rcnt;
    if(a.rnum==b.lnum)
    {
        if(a.rnum==0)
        {
            res.f=max(a.rcnt+b.lcnt,res.f);
            if(a.len==a.lcnt && a.lnum==a.rnum)
                res.lcnt=a.lcnt+b.lcnt;
            if(b.len==b.lcnt && b.lnum==b.rnum)
                res.rcnt=a.rcnt+b.rcnt;
        }
        else
        {
            res.g=max(a.rcnt+b.lcnt,res.g);
            if(a.len==a.lcnt && a.lnum==a.rnum)
                res.lcnt=a.lcnt+b.lcnt;
            if(b.len==b.lcnt && b.lnum==b.rnum)
                res.rcnt=a.rcnt+b.rcnt;
        }
    }
    return res;
}   
void init(int v,int st,int en)
{
    if(st==en)
    {
        if(arr[st]==0)
        {
            seg[v]={1,0,0,0,1,1,1};
            return;
        }
        else
        {
            seg[v]={0,1,1,1,1,1,1};
            return;
        }
    }
    int mid=(st+en)>>1;
    init(v<<1,st,mid);
    init((v<<1)|1,mid+1,en);
    seg[v]=merge(seg[v<<1],seg[(v<<1)|1]);
}
void update(int v,int st,int en,int idx,int x)
{
    if(st>idx || en<idx) return;
    if(st==en)
    {
        if(x==0)
            seg[v]={1,0,0,0,1,1,1};
        else
            seg[v]={0,1,1,1,1,1,1};
        return;
    }
    int mid=(st+en)>>1;
    update(v<<1,st,mid,idx,x);
    update((v<<1)|1,mid+1,en,idx,x);
    seg[v]=merge(seg[v<<1],seg[(v<<1)|1]);
}
T query(int v,int st,int en,int l,int r)
{
    if(st>r || en<l) return {0,0,0,0,0,0,0};
    if(st>=l && en<=r)
        return seg[v];
    int mid=(st+en)>>1;
    return merge(query(v<<1,st,mid,l,r),query((v<<1)|1,mid+1,en,l,r));
}     
int main()
{
    fastio;
    cin>>n>>q;
    string s;
    cin>>s;
    for(register int i=0;i<n;i++)
        arr[i+1]=s[i]-'0';
    init(1,1,n);
    for(register int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int a,b;
            cin>>a>>b;
            arr[a]=b;
            update(1,1,n,a,b);
        }
        else 
        {
            int l,r,x,y;
            int k1=0,k2=0;
            cin>>l>>r>>x>>y;
            if(x==0 && y==0)
            {
                cout<<-1<<'\n';
                continue;
            }
            if(x+y>r-l+1)
            {
                cout<<-1<<'\n';
                continue;
            }
            int le=l,ri=r;
            while(le<=ri)
            {
                int mid=(le+ri)>>1;
                T num=query(1,1,n,l,mid);
                if(num.f>=x && num.g>=y)
                    ri=mid-1;
                else 
                    le=mid+1;
            }
            k1=le;
            if(arr[k1]==1)
            {
                le=l,ri=k1-y;
                while(le<=ri)
                {
                    int mid=(le+ri)>>1;
                    T num=query(1,1,n,mid,k1);
                    if(num.f>=x)
                    {
                        if(num.f==x)
                            k2=mid;
                        le=mid+1;
                    }
                    else
                        ri=mid-1;
                }
                if(k2==0) k2=le;
            }
            else
            {
                le=l,ri=k1-x;
                while(le<=ri)
                {
                    int mid=(le+ri)>>1;
                    T num=query(1,1,n,mid,k1);
                    if(num.g>=y)
                    {
                        if(num.g==y) 
                            k2=mid;
                        le=mid+1;
                    }
                    else 
                        ri=mid-1;
                }
                if(k2==0) k2=le;
            }
            if(k1<k2 || k1>r || k1<l || k2>r ||  k2<l)
                cout<<-1<<'\n';
            else
                cout<<k2<<" "<<k1<<'\n';
        }
    }
}