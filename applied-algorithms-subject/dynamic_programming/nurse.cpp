#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, K1, K2;
int L0[N] = {}, L1[N] = {};

int main() {
	//input
	cin >> n >> K1 >> K2;
	
	//dp
	L0[0] = 1;
	L1[0] = 1;
	for (int i = 1; i <= n; i++) {
		//update L0
		L0[i] = L1[i-1];
		
		//update L1
		int sum = 0;
		for (int j = i - K2; j <= i - K1; j++) {
			if (j >= 0)
				sum += L0[j];
		}
		L1[i] = sum;
	}
	
	//output
	cout << L0[n] + L1[n];
}