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

    set<int> a;
    for(int x = 1; x <= n; x++) a.insert(x);

    int cur = 1;
    vector<int> res;
    while(a.size() > 1) {
        auto it = a.upper_bound(cur);
        if(it == a.end()) it = a.begin();

        if(next(it) == a.end())
            cur = *a.begin();
        else
            cur = *next(it);

        res.push_back(*it);
        a.erase(it);
    }

    res.push_back(*a.begin());

    for(int x : res) cout << x << " ";
    cout << '\n';

    return 0;
}
