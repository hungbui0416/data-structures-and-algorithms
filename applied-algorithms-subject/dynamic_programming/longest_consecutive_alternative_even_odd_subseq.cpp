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
    L[1] = 0;
    for (int i = 2; i <= n; i++) {
        if ((a[i] + a[i-1]) % 2 == 1) {
            if (L[i-1] == 0)
                L[i] = 2;
            else
                L[i] = L[i-1] + 1;
        }
        else
            L[i] = 0;
    }

    int mx = 0;
    for (int i = 2; i <= n; i++)
        mx = max(mx, L[i]);
    //output
    cout << mx;
}
