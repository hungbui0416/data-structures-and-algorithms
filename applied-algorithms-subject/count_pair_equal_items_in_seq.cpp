#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
int M[N] = {};

int main () {
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	//solve
	for (int i = 1; i <= n; i++) M[a[i]]++;
	
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (M[i] > 0) 
			cnt += M[i] * (M[i] - 1) / 2;
	}
	
	//output
	cout << cnt;
}