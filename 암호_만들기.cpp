# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
char res[100],s[100];
int n,m;
void back(int idx,int num)
{
    //printf("%d %d\n",idx,num);
    if(num>n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(res[i]=='a' || res[i]=='e' || res[i]=='i' || res[i]=='o' || res[i]=='u')
                cnt++;
        }
        if(cnt==0 || n-cnt<2) return;
        for(int i=1;i<=n;i++)
            printf("%c",res[i]);
        printf("\n");
        return;
    }
    for(int i=idx+1;i<m;i++)
    {
        res[num]=s[i];
        back(i,num+1);
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>s[i];
    sort(s,s+m);
    for(int i=0;i<=m-n;i++)
    {
        res[1]=s[i];
        back(i,2);
    }
}