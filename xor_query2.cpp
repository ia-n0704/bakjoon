#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N, Q, A[MAXN], B[MAXN];

int main()
{
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    while(Q--) {
        int l, r, k;
        cin >> l >> r >> k;

        B[l] ^= k;
        B[r+1]  ^= k;
    }

    for(int i = 1; i <= N; i++) {
        B[i] ^= B[i-1];
        cout << (A[i] ^ B[i]) << "\n";
    }
}