#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, a[N], M;
int f = 0, fmx = 0;

bool check(int i, int k) {
    if (i == 0) return true;

    if (f + a[k] <= M) return true;

    return false;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        if (check(i, k)) {
            if (i == 1) f += a[k];

            if (k == n) fmx = max(fmx, f);
            else Try(k + 1);

            if (i == 1) f -= a[k];
        }
    }
}

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> M;

    //solve - backtracking
    Try(1);

    //output
    cout << M - fmx;
}
