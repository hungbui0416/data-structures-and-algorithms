#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, c, a[N];

bool P(int d) {
    int cnt = 1;
    int pre = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - pre > d) {
            cnt++;
            if (cnt == c) return true;
            pre = a[i];
        }
    }
    return false;
}

int maxDistance(int lb, int ub) {
    if (lb == ub) return lb;

    int m = (lb + ub) / 2;
    if (P(m))
        return maxDistance(m+1, ub);
    else
        return maxDistance(lb, m);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        //input
        cin >> n >> c;
        for (int j = 1; j <= n; j++) cin >> a[j];

        //solve
        sort(a+1, a+n+1);

        int ub = (a[n] - a[1]) / (c - 1);
        cout << maxDistance(0, ub) << endl;
    }
}
