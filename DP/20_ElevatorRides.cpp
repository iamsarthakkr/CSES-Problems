#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

const pair<int, int> z = {1, 0}, inf = {int(2e9), int(2e9)};

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    const uint32_t N = 1 << n;
    vector<pair<int, int>> dp(N, inf);

    dp[0] = z;

    for(uint32_t mask = 0; mask < N; mask++) {
        for(int i = 0; i < n; i++) {

            if(((mask >> i) & 1) == 0) continue;
            uint32_t prev_mask = mask & ~(1 << i); // prev_mask < mask

            if(dp[prev_mask] == inf) continue;
            auto p = dp[prev_mask];

            if(a[i] + p.second <= x) {
                p.second += a[i];
            } else {
                p.first++;
                p.second = a[i];
            }

            if(comp(p, dp[mask])) dp[mask] = p;
        }
    }

    cout << dp[N - 1].first << '\n';

    return 0;
}
