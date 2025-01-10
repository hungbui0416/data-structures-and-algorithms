#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, L1, L2, a[N];
int L[N] = {}, ST[4*N];

void build(int id, int s, int e) {
	if (s == e)
		ST[id] = L[s];
	else {
		int m = (s + e) / 2;
		build(2*id, s, m);
		build(2*id+1, m+1, e);
		ST[id] = max(ST[2*id], ST[2*id+1]);
	}
}

int get(int id, int s, int e, int i, int j) {
	if (j < s || e < i) return 0;
	if (i <= s && e <= j) return ST[id];
	
	int m = (s + e) / 2;
	int maxL = get(2*id, s, m, i, j);
	int maxR = get(2*id+1, m+1, e, i, j);
	return max(maxL, maxR);
}

void update(int id, int s, int e, int i, int v) {
	if (i < s || e < i) return;
	if (s == e)
		ST[id] = v;
	else {
		int m = (s + e) / 2;
		update(2*id, s, m, i, v);
		update(2*id+1, m+1, e, i, v);
		ST[id] = max(ST[2*id], ST[2*id+1]);
	}
}

int main() {
	//input
	cin >> n >> L1 >> L2;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	//dp
	L[1] = a[1];
	build(1, 1, n);
	for (int i = 2; i <= n; i++) {
		L[i] = get(1, 1, n, i-L2, i-L1) + a[i];
		update(1, 1, n, i, L[i]);
	}
	
	//output
	int mx = L[1];
	for (int i = 2; i <= n; i++)
		mx = max(mx, L[i]);
	cout << mx;
}