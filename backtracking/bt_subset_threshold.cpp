#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, a[N], Y;
int sum = 0, cnt = 0;

void Try(int k) {
	for (int v = 0; v <= 1; v++) {
		if (v == 1) sum += a[k];
		
		if (k == n) {
			if (sum >= Y) cnt++;
		}
		else 
			Try(k+1);
		
		if (v == 1) sum -= a[k];
	}
}

int main() {
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> Y;
	
	//backtracking
	Try(1);
	
	//output
	cout << cnt;
}