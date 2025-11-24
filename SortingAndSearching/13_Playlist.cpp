#include <algorithm>
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> all(a.begin(), a.end());
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    for(int &x : a) x = int(lower_bound(all.begin(), all.end(), x) - all.begin());

    int bad_cnt = 0;
    vector<int> cnt(all.size());

    auto Add = [&](int x) {
        cnt[x]++;
        if(cnt[x] > 1) bad_cnt++;
    };

    auto Erase = [&](int x) {
        cnt[x]--;
        if(cnt[x] == 1) bad_cnt--;
    };

    int ans = 0;
    for(int i = 0, l = 0; i < n; i++) {
        Add(a[i]);
        while(bad_cnt >= 1) {
            Erase(a[l++]);
        }
        ans = max(ans, i - l + 1);
    };
    cout << ans << '\n';

    return 0;
}
