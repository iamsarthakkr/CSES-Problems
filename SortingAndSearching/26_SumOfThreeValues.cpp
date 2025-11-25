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
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    int l = 0, m = 1, r = n - 1;

    while(l + 1 < r) {
        if(m >= r) {
            l++;
            m = l + 1;
            r = n - 1;
            continue;
        }
        long long sum = a[l].first + a[m].first + a[r].first;
        if(sum == x) {
            cout << a[l].second << " " << a[m].second << " " << a[r].second << '\n';
            return 0;
        }
        if(sum > x) {
            r--;
        } else {
            m++;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
