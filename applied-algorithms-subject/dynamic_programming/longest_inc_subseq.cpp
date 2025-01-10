#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n, a[N];
int L[N];

int main() {
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	//dp
	L[1] = 1;
	for (int i = 2; i <= n; i++) {
		int mx = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j])
				mx = max(mx, L[j] + 1);
		}
		L[i] = mx;
	}
	
	//output
	int mx = 1;
	for (int i = 2; i <= n; i++)
		mx = max(mx, L[i]);
	
	cout << mx;
}