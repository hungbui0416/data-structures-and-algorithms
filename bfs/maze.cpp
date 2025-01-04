#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int N = 1005;
int n, m, r, c, A[N][N];
int s[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


int solve() {
	queue<ii> Q;
	Q.push({r, c});
	A[r][c] = -1;
	s[r][c] = 0;
	
	while (!Q.empty()) {
		ii u = Q.front();
		Q.pop();
		int x = u.first, y = u.second;
		
		for (int i = 0; i < 4; i++)	{
			int nx = x + dx[i], ny = y + dy[i];
			
			if (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1)
				return s[x][y] + 1;
			
			if (A[nx][ny] == 0) {
				Q.push({nx, ny});
				A[nx][ny] = -1;
				s[nx][ny] = s[x][y] + 1;
			}
		}	
	}
	
	return -1;
}

int main() {
	//input
	cin >> n >> m >> r >> c;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> A[i][j];
		
	//output
	cout << solve();
}