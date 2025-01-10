#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
int L[N];

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //dp
    L[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i-1])
            L[i] = L[i-1] + 1;
        else
            L[i] = 1;
    }

    int mx = 1;
    for (int i = 2; i <= n; i++)
        mx = max(mx, L[i]);
    //output
    cout << mx;
}
