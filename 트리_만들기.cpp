#include <stdio.h>

int n;
int cnt[1010];
int res;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&cnt[i]);
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==1)
        {
            int j;
            for(j=i+1;j<=n;j++)
            {
                if(cnt[j]==1) break;
            }
            int num=(n-i)+(j-i-1);
            if(res<num) res=num;
        }
    }
    printf("%d",res);
}