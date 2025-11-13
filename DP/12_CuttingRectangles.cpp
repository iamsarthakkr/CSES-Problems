#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

const int inf = 2e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, inf));
    dp[0][0] = 0;

    for(int w = 1; w <= a; w++) {
        for(int h = 1; h <= b; h++) {
            if(w == h) {
                dp[w][h] = 0;
                continue;
            }
            for(int x = 1; x < w; x++) {
                cmin(dp[w][h], 1 + dp[w - x][h] + dp[x][h]);
            }
            for(int y = 1; y < h; y++) {
                cmin(dp[w][h], 1 + dp[w][h - y] + dp[w][y]);
            }
        }
    }
    cout << dp[a][b] << '\n';

    return 0;
}
