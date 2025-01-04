#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int N = 1e5 + 5;
int n;
ii s[N];

int main() {
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i].first >> s[i].second;

    //solve
    sort(s+1, s+n+1, [](ii s1, ii s2) {
        return s1.second < s2.second;
    });

    int cnt = 1;
    int pre = s[1].second;
    for (int i = 2; i <= n; i++) {
        if (s[i].first > pre) {
            cnt++;
            pre = s[i].second;
        }
    }

    //output
    cout << cnt;
}
