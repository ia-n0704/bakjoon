# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define MAX_PARENT 20
vector<int> tree[MAX];
int parent[MAX][MAX_PARENT];
int depth[MAX];
bool visited[MAX];
int ch[MAX];
int check[MAX];
int sz[MAX];
int a,b;
int n;

void getDepth(int cur, int _depth) {
	visited[cur] = true;
	depth[cur] = _depth;

	int size = tree[cur].size();
	for (int i = 0; i < size; i++) {
		if (!visited[tree[cur][i]]) {
			parent[tree[cur][i]][0] = cur;
			getDepth(tree[cur][i], _depth + 1);
		}
	}
}

void connect() {
	for (int k = 1; k < MAX_PARENT; k++) {
		for (int cur = 1; cur <= n; cur++) {
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	for (int i = 0; diff != 0; i++) {
		if ((diff & 1) == 1) u = parent[u][i];
		diff = diff >> 1;
	}

	if (u != v) {
		for (int i = MAX_PARENT - 1; i >= 0; i--) {
			if (parent[u][i] != 0 && 
				parent[u][i] != parent[v][i]) {
				u = parent[u][i]; v = parent[v][i];
			}
		}
		u = parent[u][0];
	}

	return u;
}
int cnt=0;
int cnt2=1;
int res;
void dfs(int x)
{
    //cout<<x<<" "<<cnt2<<" | "<<cnt <<'\n';
    if(ch[x]==1)
    {
        if(x!=1)
        {
            cnt++;
            dfs(parent[x][0]);
        }
    }
    if(ch[x]==0)
    {
        cnt2++;
        ch[x]=1;        
    }
    if(cnt2==n)
    {
        res=min(res,cnt);
        return;
    }
    vector<pair<int,int>> v;
    for(auto i:tree[x])
    {
        if(ch[i]==0 && parent[x][0]!=i)
            v.push_back({sz[i],i});
    }
    sort(v.begin(),v.end());
    for(auto i:v)
    {
        cnt++;
        dfs(i.second);
    }
    if(x!=1) 
    {
        cnt++;
        dfs(parent[x][0]);
    }
}
void go(int x)
{
    sz[x]=1;
    for(auto i:tree[x])
    {
        if(check[i]==0)
        {
            check[i]=1;
            go(i);
            sz[x]+=sz[i];
        }
    }
    //cout<<x<<" : "<<sz[x]<<'\n';
}

void sol()
{
    cin>>n;
    res=n*2;
    cin>>a>>b;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    getDepth(1,0);
    connect();
    check[1]=1;
    go(1);
    //cout<<" | "<<sz[1]<<'\n';
    int ver=LCA(a,b);
    //cout<<ver<<" ";
    int num=depth[a]-depth[ver]+depth[b]-depth[ver];
    if(num==1)
    {
        cnt2++;
        ch[a]=1;
    }
    num+=num%2;
    //cout<<num<<'\n';
    ch[b]=1;
    dfs(b);
    if(n==2 && a!=b)
        cout<<2<<'\n';
    else
        cout<<num+res<<'\n';
    cnt=0;
    cnt2=1;
    for(int i=1;i<=n;i++)
    {
        tree[i].clear();
        fill(parent[i],parent[i]+MAX_PARENT,0);
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
        depth[i]=1;
        check[i]=0;
        ch[i]=0;
        sz[i]=0;
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