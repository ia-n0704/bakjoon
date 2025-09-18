#include <bits/stdc++.h>
using namespace std;
int st[300010],sz;
void push(int x)
{
    st[++sz]=x;
}
int pop()
{
    if(sz==0) return -1;
    return st[sz--];
}
int top()
{
    if(sz==0) return -1;
    return st[sz];
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        char s[10];
        int a;
        scanf("%s",s);
        if(strcmp(s,"PUSH")==0)
        {
            scanf("%d",&a);
            push(a);
        }
        else if(strcmp(s,"TOP")==0) printf("%d\n",top());
        else if(strcmp(s,"POP")==0) printf("%d\n",pop());
    }
    printf("%d\n",sz);
    for(int i=1;i<=sz;i++) printf("%d ",st[i]);
}