#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 1e9;
int n, K, Q;
int d[N];
int c[N][N], cmn = INF;
int x[N], y[N] = {};
int visited[N] = {};
int nbp[N] = {};
int nbt = 0, segments = 0;
int f = 0, fmn = INF;

bool check_x(int v, int k, int t) {
    if (v == 0) return true;

    if (visited[v]) return false;

    if (nbp[k] + d[v] > Q) return false;

    return true;
}

void Try_x(int k, int t) {
    if (t == 0) {
        if (k < K) Try_x(k+1, y[k+1]);
        return;
    }

    for (int v = 0; v <= n; v++) {
        if (check_x(v, k, t)) {
            x[t] = v;
            if (v > 0) {
                visited[v] = true;
                nbp[k] += d[v];
            }
            segments++;
            f += c[t][v];

            if (v == 0) {
                if (k == K) {
                    if (segments == nbt + n)
                        fmn = min(fmn, f);
                }
                else if (f + cmn * (nbt + n - segments) < fmn)
                    Try_x(k+1, y[k+1]);
            }
            else if (f + cmn * (nbt + n - segments) < fmn)
                Try_x(k, v);

            if (v > 0) {
                visited[v] = false;
                nbp[k] -= d[v];
            }
            segments--;
            f -= c[t][v];
        }
    }
}

bool check_y(int v, int k) {
    if (v == 0) return true;

    if (visited[v]) return false;

    return true;
}

void Try_y(int k) {
    int s = 0;
    if (y[k-1] > 0) s = y[k-1] + 1;

    for (int v = s; v <= n; v++) {
        if (check_y(v, k)) {
            y[k] = v;
            if (v > 0) {
                visited[v] = true;
                f += c[0][v];
                nbp[k] += d[v];
                nbt++; segments++;
            }

            if (k == K) Try_x(1, y[1]);
            else Try_y(k+1);

            if (v > 0) {
                visited[v] = false;
                f -= c[0][v];
                nbp[k] -= d[v];
                nbt--; segments--;
            }
        }
    }
}

int main() {
    //input
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j) cmn = min(cmn, c[i][j]);
        }
    }

    //solve - branch & bound backtracking
    Try_y(1);

    //output
    cout << fmn;
}
