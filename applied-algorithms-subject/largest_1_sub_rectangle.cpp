#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, A[N][N];
int h[N] = {}, L[N], R[N];

int main() {
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> A[i][j];
		
	//solve
	int mx = 0;
	h[0] = -1; h[m+1] = -1;
	for (int i = 1; i <= n; i++) {
		//update h
		for (int j = 1; j <= m; j++) {
			if (A[i][j] == 1) h[j]++;
			else h[j] = 0;
		}
		
		//update R
		stack<int> S;
		for (int j = 1; j <= m + 1; j++) {
			while (!S.empty()) {
				if (h[j] < h[S.top()]) {
					R[S.top()] = j;
					S.pop();
				}
				else break;
			}
			S.push(j);
		}
		
		//update L
		S.pop(); //clear S
		for (int j = m; j >= 0; j--) {
			while (!S.empty()) {
				if (h[j] < h[S.top()]) {
					L[S.top()] = j;
					S.pop();
				}
				else break;
			}
			S.push(j);
		}
		
		//update mx
		for (int j = 1; j <= m; j++)
			mx = max(mx, h[j] * (R[j] - L[j] - 1));
	}
	
	//ouput
	cout << mx;
}