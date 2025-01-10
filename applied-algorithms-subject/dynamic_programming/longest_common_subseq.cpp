#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m, x[N], y[N];
int L[N][N];

int main() {
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];
	
	//dp
	for (int i = 0; i <= n; i++) L[i][0] = 0;
	for (int i = 0; i <= m; i++) L[0][i] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i] == y[j])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	
	//output
	cout << L[n][m];
}