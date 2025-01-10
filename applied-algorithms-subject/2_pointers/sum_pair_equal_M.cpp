#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, M, a[N];

int main() {
    //input
    cin >> n >> M;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //2 pointers
    sort(a + 1, a + n + 1);

    int cnt = 0;
    int i = 1, j = n;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum == M) {
            cnt++;
            i++; j--;
        }
        else if (sum < M) i++;
        else j--;
    }

    //output
    cout << cnt;
}
