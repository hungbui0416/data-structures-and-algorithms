#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int INF = 1e9;
int n, a[N];
long long L0[N], L1[N];
bool F0[N], F1[N];

int main() {
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	//dp
	if (a[1] % 2 == 0) {
		L0[1] = a[1]; 
		F0[1] = true; F1[1] = false;
	}
	else {
		L1[1] = a[1];
		F0[1] = false; F1[1] = true;
	}
	
	for (int i = 2; i <= n; i++) {
		//even
		if (a[i] % 2 == 0) {
			//update L0 & F0
			if (F0[i-1] && L0[i-1] > 0)
				L0[i] = L0[i-1] + a[i];
			else
				L0[i] = a[i];
			F0[i] = true;
			
			//update L1 & F1
			if (F1[i-1]) {
				L1[i] = L1[i-1] + a[i];
				F1[i] = true;
			}
			else
				F1[i] = false;
		}
		//odd
		else {
			//update L0 & F0
			if (F1[i-1]) {
				L0[i] = L1[i-1] + a[i];
				F0[i] = true;
			}
			else
				F0[i] = false;
				
			//update L1 & F1
			if (F0[i-1] && L0[i-1] > 0)
				L1[i] = L0[i-1] + a[i];
			else
				L1[i] = a[i];
			F1[i] = true;
		}
	}
	
	//cout
	long long mx = -INF;
	for (int i = 1; i <= n; i++) {
		if (F0[i]) mx = max(mx, L0[i]);
	}
	
	cout << mx;
}