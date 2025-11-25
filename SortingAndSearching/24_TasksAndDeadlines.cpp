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

    vector<int> duration(n), deadline(n);
    for(int i = 0; i < n; i++) cin >> duration[i] >> deadline[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return duration[i] < duration[j]; });

    long long start = 0, ans = 0;
    for(int i : order) {
        long long end = start + duration[i];
        ans += deadline[i] - end;
        start = end;
    }

    cout << ans << '\n';

    return 0;
}
