int main()
{
    int n, m, s, c=1, t, ans=0;
    char v[52];
    scanf("%d%d",&n,&m);
    for(int r=0;r<m;r++)
    {
        scanf("%d",&s);
        for(t=0;c!=s;c=c%n+1)
            t+=v[c]==0;
        ans+=(t<n-r-t)?t:n-r-t;
        v[c]=1;
    }
    printf("%d",ans);
} 