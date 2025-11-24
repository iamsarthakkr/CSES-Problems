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

    int n = 8;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;

    auto good = [&](const vector<int> &rows, int c) -> bool {
        int r = (int)rows.size();
        assert(r < n);

        if(s[r][c] == '*') return false;

        for(int rr = 0; rr < (int)rows.size(); rr++) {
            int cc = rows[rr];
            if(cc == c) return false; // same col
            int d1 = abs(cc - c), d2 = abs(rr - r);
            if(d1 == d2) return false;
        }

        return true;
    };

    int calls = 0;
    function<void(vector<int> &)> go = [&](vector<int> &rows) {
        calls++;
        if((int)rows.size() == n) {
            ans += 1;
            return;
        }

        for(int c = 0; c < n; c++) {
            if(good(rows, c)) {
                rows.push_back(c);
                go(rows);
                rows.pop_back();
            }
        }
    };

    vector<int> rows;
    go(rows);
    debug(calls);

    cout << ans << '\n';

    return 0;
}
