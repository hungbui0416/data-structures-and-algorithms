#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int INF = 1e9;
int n, a[N];
int f0 = 0, f1 = 0, difmn = INF;

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        if (i == 0) f0 += a[k];
        else f1 += a[k];

        if (k == n) difmn = min(difmn, abs(f0 - f1));
        else Try(k + 1);

        if (i == 0) f0 -= a[k];
        else f1 -= a[k];
    }
}

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //solve - backtracking
    Try(1);

    //output
    cout << difmn;
}
