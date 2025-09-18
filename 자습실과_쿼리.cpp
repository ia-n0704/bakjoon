#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, k, sum[300002], a, b, d, l, r, ld, rd;

int main(void) {
	scanf("%lld %lld %lld", &n, &m, &k);
	for (long long i = 1;i <= m;i++) {
		scanf("%lld %lld", &a, &b);
		sum[a] = b;
	}

	for (long long i = 1;i <= n + 1;i++) {
		sum[i] += sum[i - 1];
	}

	l = 0, r = n + 1;
	for (long long i = 1;i <= k;i++) {
		ld = rd = 0;
		scanf("%lld", &d);
		if (l == r) {
			printf("0\n");
		}
		else {
			if (d - 1 > l) {
				if (r < d) {
					ld = sum[d - 1] - sum[l] - (sum[d - 1] - sum[r]);
				}
				else {
					ld = sum[d - 1] - sum[l];
				}
			}

			if (d + 1 < r) {
				if (l > d) {
					rd = sum[r] - sum[d] - (sum[l] - sum[d]);
				}
				else {
					rd = sum[r] - sum[d];
				}
			}

			printf("%lld\n", min(ld, rd));
			if (ld < rd) {
				l = min(d - 1, r);
			}
			else if (ld == rd) {
				if (d - 1 <= n - d) {
					l = min(d - 1, r);
				}
				else {
					r = max(d + 1, l);
				}
			}
			else {
				r = max(d + 1, l);
			}
		}
	}

	return 0;
}