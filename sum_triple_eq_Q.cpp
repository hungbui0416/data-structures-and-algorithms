#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, a[N], Q;
int M[1000005];

int main() {
    //input
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //solve
    for (int i = 1; i <= n; i++) {
        if (Q > a[i]) M[Q - a[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = a[i] + a[j];
            if (M[sum] > j)
                cnt++;
        }
    }
    //output
    cout << cnt;
}
