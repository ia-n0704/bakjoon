/*#include <bits/stdc++.h>
using namespace std;
int arr[1024][1024];
int sum[1024];
int n;
int num=1;
int temp;
queue <int> q[1024];
void dfs(int v)
{
    while(!q[v].empty())
    {
        int a=q[v].front();
        q[v].pop();
        if(arr[v][a])
        {
            arr[v][a]--;
            arr[a][v]--;
            dfs(a);
        }
    }
    cout<<v<<" ";
    temp++;
    if(num<=temp) exit(0);    
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            sum[i]+=arr[i][j];
            if(i<j) num+=arr[i][j];
            for(int r=0;r<arr[i][j];r++)
                q[i].push(j);
        }     
    }
    for(int i=1;i<=n;i++)
    {
        if(sum[i]%2)
        {
            cout<<-1;
            return 0;
        }
    }
    dfs(1);
}*/


#include <bits/stdc++.h>
using namespace std;


int N;
vector<int> v[1001];
int arr[1001][1001];
int line[1001];
int ch[1001][1001];
vector<int> res;

void dfs(int n){
    for (int j=0;j<v[n].size();j++){
        int i=v[n][i];
        if (arr[n][i]>0){
            arr[n][i]--;
            arr[i][n]--;
            if(arr[n][i]==0)
            {
                v[i].erase(v[i].begin()+j+1);
                v[n].erase(v[n].begin()+j+1);
            }
            dfs(i);
        }
    }
    res.push_back(n+1);
}
int len = 0;
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]) v[i].push_back(j);
            line[i]+=arr[i][j];
        }
    }
    int odd_cnt = 0;
    for (int i = 0; i < N; i++){
        if(line[i] % 2 == 1) odd_cnt++;
    }
    if (odd_cnt != 0){
        printf("-1");
        return 0;
    }
    dfs(0);
    int flag=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            if(arr[i][j]) flag=1;
    }
    if(flag)
    {
        printf("-1");
        return 0;
    }
    for(auto i:res) cout<<i<<" ";
    return 0;
}