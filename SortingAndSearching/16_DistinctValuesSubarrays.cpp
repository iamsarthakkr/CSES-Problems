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

    {
        // compress

        vector<int> all = a;
        sort(all.begin(), all.end());
        all.resize(unique(all.begin(), all.end()) - all.begin());
        for(int &x : a) x = int(lower_bound(all.begin(), all.end(), x) - all.begin());
    }

    vector<int> cnt(n, 0);
    int bad = 0;

    auto Add = [&](int x) {
        cnt[x]++;
        if(cnt[x] > 1) bad++;
    };
    auto Erase = [&](int x) {
        cnt[x]--;
        if(cnt[x] == 1) bad--;
    };

    long long ans = 0;
    int l = 0;
    for(int r = 0; r < n; r++) {
        Add(a[r]);
        while(bad > 0) Erase(a[l++]);

        ans += r - l + 1;
    }
    cout << ans << '\n';

    return 0;
}
