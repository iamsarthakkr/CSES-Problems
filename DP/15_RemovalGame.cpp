#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

const int N = 5001;
long long dp[N][N][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int l = 0; l < n; l++) {
        dp[l][l][0] = a[l];
        dp[l][l][1] = 0;
    }

    for(int len = 2; len <= n; len++) {
        for(int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            {
                // us
                dp[l][r][0] = max(a[l] + dp[l + 1][r][1], a[r] + dp[l][r - 1][1]);
            }
            {
                // him
                dp[l][r][1] = min(dp[l + 1][r][0], dp[l][r - 1][0]);
            }
        }
    }

    cout << dp[0][n - 1][0] << '\n';

    return 0;
}
