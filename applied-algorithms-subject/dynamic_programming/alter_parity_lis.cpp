#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int N = 1e5 + 5;
int n, a[N];

void build(int *ST, int *t, int id, int s, int e) {
	if (s == e)
		ST[id] = t[s];
	else {
		int m = (s + e) / 2;
		build(ST, t, 2*id, s, m);
		build(ST, t, 2*id+1, m+1, e);
		ST[id] = max(ST[2*id], ST[2*id+1]);
	}
}

int get(int *ST, int id, int s, int e, int i, int j) {
	if (j < s || e < i) return 0;
	if (i <= s && e <= j) return ST[id];

	int m = (s + e) / 2;
	int maxL = get(ST, 2*id, s, m, i, j);
	int maxR = get(ST, 2*id+1, m+1, e, i, j);
	return max(maxL, maxR);
}

void update(int *ST, int id, int s, int e, int i, int v) {
	if (i < s || e < i) return;
	if (s == e)
		ST[id] = v;
	else {
		int m = (s + e) / 2;
		update(ST, 2*id, s, m, i, v);
		update(ST, 2*id+1, m+1, e, i, v);
		ST[id] = max(ST[2*id], ST[2*id+1]);
	}
}

void solve() {
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	//solve
	//compress
    ii b[n+1];
    for (int i = 1; i <= n; i++) b[i] = {a[i], i};
    sort(b+1, b+n+1);
    int tmp[n+1];
    for (int i = 1; i <= n; i++) tmp[b[i].second] = i;

	//dp
	int L[n+1], t[n+1] = {};
	int ST0[4*n+4] = {}, ST1[4*n+4] = {};
	build(ST0, t, 1, 1, n);
	build(ST1, t, 1, 1, n);
	L[1] = 1;
	t[tmp[1]] = L[1];
	if (a[1] % 2 == 0)
		update(ST0, 1, 1, n, tmp[1], L[1]);
	else
		update(ST1, 1, 1, n, tmp[1], L[1]);

	for (int i = 2; i <= n; i++) {
		if (a[i] % 2 == 0) {
			L[i] = get(ST1, 1, 1, n, 1, tmp[i]-1) + 1;
			t[tmp[i]] = L[i];
			update(ST0, 1, 1, n, tmp[i], L[i]);
		}
		else {
			L[i] = get(ST0, 1, 1, n, 1, tmp[i]-1) + 1;
			t[tmp[i]] = L[i];
			update(ST1, 1, 1, n, tmp[i], L[i]);
		}
	}

	//output
	int mx = 1;
	for (int i = 2; i <= n; i++)
		mx = max(mx, L[i]);
	cout << mx << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve();
}
