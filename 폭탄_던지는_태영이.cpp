/*#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[2024][2024];
int ans[2024][2024];
int sum[2024][2024];
int lsum[2024][2024];
int rsum[2024][2024];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            arr[i][j]*=-1;
        }
    }
    int w=m/2;
    for(int i=n-w;i>=w+1;i--)
    {
        for(int j=w;j<=n-w;j++)
        {
            int temp=arr[i+w][j-w];
            ans[i][j]=temp-sum[i][j-1]-lsum[i+1][j];
            sum[i][j]=sum[i][j-1]+sum[i+1][j]+ans[i][j]-sum[i+1][j-1];
            if(j>=w+1)
                sum[i][j]-=ans[i][j-w-1];
            if(i+w+1<=n)
                sum[i][j]-=rsum[i+w+1][j];
            lsum[i][j]=lsum[i+1][j]+ans[i][j];
            if(i+w+1<=n)
                lsum[i][j]-=ans[i+w+1][j];
            rsum[i][j]=rsum[i][j-1]+ans[i][j];
            if(j>=w+1)
                rsum[i][j]-=ans[i][j-w-1];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> arr, sum;
int N, M;
ll getSum(int y, int x) {
	int yy = max(0, y - M), xx = max(0, x - M);
	return sum[y][x] - sum[yy][x] - sum[y][xx] + sum[yy][xx];
}
int main() {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N >> M;
	arr.resize(N + 1, vector<ll>(N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			arr[i][j] *= -1;
		}
	}
	if (M == 1) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << arr[i][j] << ' ';
			}
            cout<<'\n';
		}
		return 0;
	}
	sum.resize(N + 1, vector<ll>(N + 1));
	vector<vector<ll>> ans(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

			ll diff = arr[i][j] - getSum(i, j);
			if (diff > 0) {
				sum[i][j] += diff;
				ans[i + M / 2][j + M / 2] += diff;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << ans[i][j] << ' ';
		}
        cout<<'\n';
	}
	return 0;
}