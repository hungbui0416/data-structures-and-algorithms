#include <bits/stdc++.h>
using namespace std;

struct Treasure {
    int x;
    int y;
    int c;

    Treasure(int _x, int _y, int _c) : x(_x), y(_y), c(_c) {}
};

const int N = 1005;
int n;
vector<Treasure> T;
long long L[N];

int main() {
    //input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        T.push_back(Treasure(x, y, c));
    }
    //dp
    sort(T.begin(), T.end(), [](Treasure a, Treasure b) {
        if (a.x == b.x) return a.y < b.y;
        else return a.x < b.x;
    });

    L[0] = T[0].c;
    for (int i = 1; i < n; i++) {
        long long mx = 0;
        for (int j = 0; j < i; j++) {
            if (T[i].y >= T[j].y)
                mx = max(mx, L[j]);
        }
        L[i] = mx + T[i].c;
    }

    long long mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, L[i]);
    //output
    cout << mx;
}
