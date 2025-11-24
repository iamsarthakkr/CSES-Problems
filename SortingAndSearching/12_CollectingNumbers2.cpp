#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, q;
    cin >> n >> q;

    vector<int> a(n), pos(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    int ans = 1;
    auto Update = [&](int x, int delta) {
        if(x == 0 || x >= n) return;
        if(pos[x] < pos[x - 1]) ans += delta;
    };

    for(int i = 0; i < n; i++) Update(i, +1);
    debug(ans);

    while(q--) {
        int i, j;
        cin >> i >> j;
        --i, --j;

        int x = a[i];
        int y = a[j];

        if(x > y) swap(x, y);

        Update(x, -1);
        if(x + 1 != y) Update(x + 1, -1);
        Update(y, -1);
        Update(y + 1, -1);

        swap(a[i], a[j]);
        swap(pos[x], pos[y]);

        Update(x, +1);
        if(x + 1 != y) Update(x + 1, +1);
        Update(y, +1);
        Update(y + 1, +1);

        cout << ans << '\n';
    }

    return 0;
}
