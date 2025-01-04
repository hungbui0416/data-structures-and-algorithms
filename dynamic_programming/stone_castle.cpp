#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 105;
int L, W, H, n;
int MW[M][M][M];

void init() {
    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= W; j++)
            for (int k = 1; k <= H; k++)
                MW[i][j][k] = i * j * k;
}

void input() {
    cin >> L >> W >> H >> n;
    init();
    for (int i = 0; i < n; i++) {
        int l, w, h;
        cin >> l >> w >> h;
        MW[l][w][h] = 0; MW[l][h][w] = 0;
        MW[w][l][h] = 0; MW[w][h][l] = 0;
        MW[h][l][w] = 0; MW[h][w][l] = 0;
    }
}

void solve() {
    for(int i = 1; i <= L; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 1; k <= H; k++) {
                int mw = MW[i][j][k];
                for (int t = 1; t < i; t++)
                    mw = min(mw, MW[t][j][k] + MW[i-t][j][k]);

                for (int t = 1; t < j; t++)
                    mw = min(mw, MW[i][t][k] + MW[i][j-t][k]);

                for (int t = 1; t < k; t++)
                    mw = min(mw, MW[i][j][t] + MW[i][j][k-t]);

                MW[i][j][k] = mw;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        input();
        solve();
        cout << MW[L][W][H] << endl;
    }
}
