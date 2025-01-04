#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
const int A = 1e4;
int n, a[N];
int d[N], t[N] = {}, st[4*N];

void build(int id, int s, int e) {
    if (s == e) {
        st[id] = t[s];
        return;
    }

    int m = (s + e) / 2;
    build(2*id, s, m);
    build(2*id+1, m+1, e);

    st[id] = max(st[2*id], st[2*id+1]);
}

int get(int id, int s, int e, int i, int j) {
    if (j < s || e < i) return 0;

    if (i <= s && e <= j) return st[id];

    int m = (s + e) / 2;
    int maxL = get(2*id, s, m, i, j);
    int maxR = get(2*id+1, m+1, e, i, j);

    return max(maxL, maxR);
}

void update(int id, int s, int e, int i, int v) {
    if (s == e) {
        st[id] = v;
        return;
    }

    int m = (s + e) / 2;
    if (i > m) update(2*id+1, m+1, e, i, v);
    else update(2*id, s, m, i, v);

    st[id] = max(st[2*id], st[2*id+1]);
}

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //dp
    d[1] = 1;
    t[a[1]] = 1;
    build(1, 1, A);
    for (int i = 2; i <= n; i++) {
        d[i] = get(1, 1, A, 1, a[i]-1) + 1;
        t[a[i]] = d[i];
        update(1, 1, A, a[i], d[i]);
    }

    //output
    int mx = 1;
    for (int i = 2; i <= n; i++)
        mx = max(mx, d[i]);

    cout << mx;
}
