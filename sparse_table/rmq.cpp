#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int L = log2(N);
int n, a[N];
int M[N][L];

int main() {
    //input
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    //build sparse table
    for (int i = 0; i < n; i++) M[i][0] = a[i];

    for (int j = 1; 1 << j <= n; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            M[i][j] = min(M[i][j-1], M[i+(1<<(j-1))][j-1]);

    //query
    int m;
    cin >> m;
    long long sum = 0;
    for (int t = 0; t < m; t++) {
        int i, j;
        cin >> i >> j;

        int k = log2(j-i+1);
        sum += min(M[i][k], M[j-(1<<k)+1][k]);
    }

    //output
    cout << sum;
}
