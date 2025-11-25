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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<long long, vector<pair<int, int>>> mp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            long long sum = a[i] + a[j];
            long long need = x - sum;
            if(mp.find(need) != mp.end()) {
                for(auto &[k, l] : mp[need]) {
                    if(k == i || k == j || l == i || l == j) continue;
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << '\n';
                    debug(clock());
                    return 0;
                }
            }
        }
        for(int j = i + 1; j < n; j++) {
            long long sum = a[i] + a[j];
            mp[sum].emplace_back(i, j);
        }
    }

    debug(clock());

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
