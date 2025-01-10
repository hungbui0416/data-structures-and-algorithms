#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
int M[N] = {};

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //prefix sum 1D
    for (int i = 1; i <= n; i++) M[i] = M[i-1] + a[i];

    //query
    int Q;
    cin >> Q;
    for (int k = 0; k < Q; k++) {
        int i, j;
        cin >> i >> j;
        cout << M[j] - M[i-1] << endl;
    }
}
