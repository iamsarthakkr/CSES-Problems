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

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    while(l < r) {
        int cs = a[l].first + a[r].first;
        if(cs == x) break;
        if(cs > x)
            r--;
        else
            l++;
    }

    if(l >= r) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << a[l].second + 1 << " " << a[r].second + 1 << '\n';
    }

    return 0;
}
