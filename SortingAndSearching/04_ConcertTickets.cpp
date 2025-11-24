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

    int n, m;
    cin >> n >> m;
    multiset<int> avail;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        avail.insert(x);
    }

    for(int i = 0, x; i < m; i++) {
        cin >> x;
        auto it = avail.upper_bound(x);
        if(it == avail.begin()) {
            cout << -1 << '\n';
            continue;
        }
        it = prev(it);
        cout << *it << '\n';
        avail.erase(it);
    }

    return 0;
}
