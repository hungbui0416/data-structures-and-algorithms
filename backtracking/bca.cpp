#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int INF = 1e9;
int m, n;
vector<int> T[N];
bool C[N][N] = {};
int x[N];
int load[N] = {}, loadmn = INF;

bool check(int t, int k) {
	for (int c = 1; c < k; c++) {
		if (x[c] == t && C[c][k]) return false;
	}
	
	return true;
}

void Try(int k) {
	for (int t : T[k]) {
		if (check(t, k)) {
			x[k] = t;
			load[t]++;
			
			if (k == n) {
				int mx = 0;
				for (int i = 1; i <= m; i++)
					mx = max(mx, load[i]);
				loadmn = min(loadmn, mx);
			}
			else if (load[t] <= loadmn) Try(k+1);
			
			load[t]--;
		}
	}
}

int main() {
	//input
	cin >> m >> n;
	for (int t = 1; t <= m; t++) {
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int c;
			cin >> c;
			T[c].push_back(t);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		C[c1][c2] = C[c2][c1] = true;
	}
	
	//branch and bound backtracking
	Try(1);
	
	//output
	cout << loadmn;
}