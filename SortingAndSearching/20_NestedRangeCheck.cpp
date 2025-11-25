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
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    {
        // contains other

        debug(order);
        sort(order.begin(), order.end(), [&](int i, int j) {
            if(r[i] == r[j]) return l[i] > l[j];
            return r[i] < r[j];
        });
        vector<int> has(n);
        set<int> ls;
        for(int i : order) {
            auto it = ls.lower_bound(l[i]);
            if(it != ls.end()) has[i] = 1;
            ls.insert(l[i]);
        }

        for(int i = 0; i < n; i++) cout << has[i] << " \n"[i == n - 1];
    }

    {
        // contained by other

        sort(order.begin(), order.end(), [&](int i, int j) {
            if(l[i] == l[j]) return r[i] > r[j];
            return l[i] < l[j];
        });
        debug(order);

        vector<int> has(n);
        set<int> rs;
        for(int i : order) {
            auto it = rs.lower_bound(r[i]);
            if(it != rs.end()) has[i] = 1;
            rs.insert(r[i]);
        }

        for(int i = 0; i < n; i++) cout << has[i] << " \n"[i == n - 1];
    }
    return 0;
}
