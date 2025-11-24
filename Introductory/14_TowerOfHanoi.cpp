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

    int n;
    cin >> n;

    vector<pair<int, int>> res;
    function<void(int, int, int, int)> solve = [&](int from, int to, int mid, int cnt) {
        if(cnt == 0) return;

        solve(from, mid, to, cnt - 1);
        res.emplace_back(from, to);
        solve(mid, to, from, cnt - 1);
    };

    solve(1, 3, 2, n);

    cout << (int)res.size() << '\n';
    for(auto &[a, b] : res) cout << a << " " << b << '\n';

    return 0;
}
