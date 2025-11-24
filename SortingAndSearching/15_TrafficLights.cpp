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

    int n, X;
    cin >> X >> n;

    set<int> bad;
    multiset<int> dists;

    auto Add = [&](int x) {
        debug(x);
        auto ret = bad.insert(x);
        assert(ret.second);
        auto it = ret.first;

        if(it != bad.begin()) {
            int d = *it - *prev(it);
            dists.insert(d);
        }
        if(next(it) != bad.end()) {
            int d = *next(it) - *it;
            dists.insert(d);
        }
        if(it != bad.begin() && next(it) != bad.end()) {
            int d = *next(it) - *prev(it);
            dists.erase(dists.find(d));
        }
    };

    Add(0);
    Add(X);

    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;

        Add(y);

        cout << *dists.rbegin() << '\n';
    }

    return 0;
}
