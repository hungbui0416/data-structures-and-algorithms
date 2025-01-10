#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int INF = 1e9;
int n, S, D;
int c[N][N], cmn = INF;
int x[N] = {};
bool visited[N] = {};
int seats = 0;
int d[N];
int f[N], fmn = INF;

bool check(int v, int k) {
    if (visited[v]) return false;

    if (v > n) {
        if (!visited[v-n]) return false;
        if (f[k-1] + c[x[k-1]][v] - f[d[v-n]] < D) return false;
    }
    else {
        if (seats == S) return false;
    }

    return true;
}

void Try(int k) {
    for (int v = 1; v <= 2*n; v++) {
        if (check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if (v > n) seats--;
            else seats++;
            f[k] = f[k-1] + c[x[k-1]][v];
            d[v] = k;

            if (k == 2*n) fmn = min(fmn, f[2*n] + c[v][0]);
            else if (f[k] + cmn * (2*n - k + 1) < fmn) Try(k + 1);

            visited[v] = false;
            if (v > n) seats++;
            else seats--;
        }
    }
}

int main() {
    //input
    cin >> n >> S >> D;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if (i != j) cmn = min(cmn, c[i][j]);
        }
    }

    //solve - b&b backtracking
    Try(1);

    //output
    if (fmn == INF) cout << -1;
    else cout << fmn;
}
