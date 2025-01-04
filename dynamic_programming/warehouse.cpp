#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, T, D, a[N], t[N];
int L[N][N];

int main() {
	//input
	cin >> n >> T >> D;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	
	//dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= T; j++) {
			if (j < t[i]) 
				L[i][j] = 0;
			else {
				int mx = 0;
				for (int k = i - D; k < i; k++) {
					if (k >= 1)
						mx = max(mx, L[k][j-t[i]]);
				}
				L[i][j] = mx + a[i];
			}
		}
	}
	
	//cout 
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, L[i][T]);
	cout << mx;
}