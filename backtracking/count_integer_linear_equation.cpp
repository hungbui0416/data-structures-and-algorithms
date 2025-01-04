#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, M , a[N];
int sum = 0, cnt = 0;

void Try(int k) {
	for (int v = 1; v < M / a[k]; v++) {
		sum += a[k] * v;
		
		if (k == n) {
			if (sum == M) cnt++;
		}
		else if (sum < M) Try(k+1);
		
		sum -= a[k] * v;
	}
}

int main() {
	//input
	cin >> n >> M;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	//branch and bound backtracking
	Try(1);
	
	//output
	cout << cnt;
}