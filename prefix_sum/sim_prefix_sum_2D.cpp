#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, a[N][N];
int M[N][N];

int main() {
    //input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }

    //prefix sum 2D
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            M[i][j] = M[i-1][j] + M[i][j-1] - M[i-1][j-1] + a[i][j];
    }

    //query
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << M[r2][c2] - M[r1-1][c2] - M[r2][c1-1] + M[r1-1][c1-1] << endl;
    }
}
