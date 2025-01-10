#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int H, W, n;
int h[N], w[N];
int marked[N][N] = {};

bool check(int x, int y, int k, int hk, int wk) {
    for (int i = x; i <= x+hk-1; i++)
        for (int j = y; j <= y+wk-1; j++)
            if (marked[i][j]) return false;

    return true;
}

void mark(int x, int y, int hk, int wk, bool v) {
    for (int i = x; i <= x+hk-1; i++)
        for (int j = y; j <= y+wk-1; j++)
            marked[i][j] = v;
}

void Try(int k) {
    for (int r = 0; r <= 1; r++) {
        int hk = h[k], wk = w[k];
        if (r == 1) {
            hk = w[k]; wk = h[k];
        }

        for (int x = 1; x <= H-hk+1; x++) {
            for (int y = 1; y <= W-wk+1; y++) {
                if (check(x, y, k, hk, wk)) {
                    mark(x, y, hk, wk, true);

                    if (k == n) {
                        cout << 1;
                        exit(0);
                    }
                    else Try(k + 1);

                    mark(x, y, hk, wk, false);
                }
            }
        }
    }
}

int main() {
    //input
    cin >> H >> W >> n;
    for (int i = 1; i <= n; i++) cin >> h[i] >> w[i];

    //backtracking
    Try(1);

    //output
    cout << 0;
}
