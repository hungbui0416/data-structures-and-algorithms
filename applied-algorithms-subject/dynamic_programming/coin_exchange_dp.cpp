#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9;
int n, x, D[N];
int M[N][N];

int main() {
	//input
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> D[i];
	
	//dp
	for (int i = 1; i <= n; i++) M[i][0] = 0;
	for (int v = 1; v <= x; v++) M[0][v] = INF;
	
	for (int i = 1; i <= n; i++) {
		for (int v = 1; v <= x; v++) {
			if (v - D[i] >= 0)
				M[i][v] = min(M[i-1][v], 1+M[i][v-D[i]]);
			else
				M[i][v] = M[i-1][v];
		}
	}
	
	//output
	cout << M[n][x];
}