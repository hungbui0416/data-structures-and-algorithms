#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, a[N];
int M[200005];

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //solve
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = a[i] + a[j];
            M[sum]++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += M[a[i]];
    //output
    cout << cnt;
}
