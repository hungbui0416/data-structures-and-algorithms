#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, Q, a[N];

int main() {
    //input
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //2 pointers
    int mx = 0;
    int i = 1, j = 1, sum = 0;
    while (j <= n) {
        sum += a[j];
        while (sum > Q) {
            sum -= a[i];
            i++;
        }
        mx = max(mx, j - i + 1);
        j++;
    }

    //output
    if (mx == 0) cout << -1;
    else cout << mx;
}
