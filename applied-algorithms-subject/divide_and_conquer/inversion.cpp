#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

int merge(int s, int m, int e) {
    long long inv = 0;
    int tmp[n+1];
    int i = s, j = m+1, k = s;

    while (i <= m && j <= e) {
        if (a[i] <= a[j]) {
            tmp[k] = a[i];
            i++; k++;
        }
        else {
            tmp[k] = a[j];
            j++; k++;
            inv += m - i + 1;
        }
    }

    while (i <= m) {
        tmp[k] = a[i];
        i++; k++;
    }

    while (j <= e) {
        tmp[k] = a[j];
        j++; k++;
    }

    for (k = s; k <= e; k++) a[k] = tmp[k];

    return inv % MOD;
}

int inversion(int s, int e) {
    if (s == e) return 0;

    int m = (s + e) / 2;
    long long L = inversion(s, m);
    long long R = inversion(m+1, e);
    long long M = merge(s, m, e);

    return (L + R + M) % MOD;
}

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //output
    cout << inversion(1, n);
}
