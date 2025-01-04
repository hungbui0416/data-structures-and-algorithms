#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
int M[4*N];

void build(int id, int s, int e) {
    if (s == e) {
        M[id] = a[s];
        return;
    }

    int m = (s + e) / 2;
    build(2*id, s, m);
    build(2*id+1, m+1, e);

    M[id] = max(M[2*id], M[2*id+1]);
}

int get(int id, int s, int e, int i, int j) {
    if (j < s || e < i) return 0;

    if (i <= s && e <= j) return M[id];

    int m = (s + e) / 2;
    int maxL = get(2*id, s, m, i, j);
    int maxR = get(2*id+1, m+1, e, i, j);

    return max(maxL, maxR);
}

void update(int id, int s, int e, int i, int v) {
    if (s == e) {
        M[id] = v;
        return;
    }

    int m = (s + e) / 2;
    if (i > m) update(2*id+1, m+1, e, i, v);
    else update(2*id, s, m, i, v);

    M[id] = max(M[2*id], M[2*id+1]);
}

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //segment tree
    build(1, 1, n);

    //query
    int m;
    cin >> m;
    for (int k = 0; k < m; k++) {
        string s;
        cin >> s;
        if (s == "update") {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, v);
        }
        else if (s == "get-max") {
            int i, j;
            cin >> i >> j;
            cout << get(1, 1, n, i, j) << endl;
        }
    }
}
