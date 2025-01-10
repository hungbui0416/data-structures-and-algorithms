#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int INF = 1e9;
int n, K;
int c[N][N], cmn = INF;
int x[N];
int visited[N] = {};
int nbp = 0;
int f = 0, fmn = INF;

bool check(int v, int k) {
    if (visited[v]) return false;

    if (v > n) {
        if (!visited[v-n]) return false;
    }
    else {
        if (nbp == K) return false;
    }

    return true;
}

void Try(int k) {
    for (int v = 1; v <= 2*n; v++) {
        if (check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if (v > n) nbp--;
            else nbp++;
            f += c[x[k-1]][v];

            if (k == 2*n)
                fmn = min(fmn, f + c[v][0]);
            else if (f + cmn * (2*n - k + 1) < fmn) Try(k+1);

            visited[v] = false;
            if (v > n) nbp++;
            else nbp--;
            f -= c[x[k-1]][v];
        }
    }
}

int main() {
    //input
    cin >> n >> K;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++)  {
            cin >> c[i][j];
            if (i != j) cmn = min(cmn, c[i][j]);
        }
    }

    //branch & bound backtracking
    Try(1);

    //output
    cout << fmn;
}
