#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

long long dp[20][2][10][2]; // len, tight, last digit, started

long long solve(long long n) {
    if(n < 0) return 0;
    if(n == 0) return 1;

    vector<int> d;
    long long y = n;
    while(y) {
        d.push_back(int(y % 10));
        y /= 10;
    }
    reverse(d.begin(), d.end());
    int m = (int)d.size();

    memset(dp, 0, sizeof(dp));
    dp[0][1][0][0] = 1;

    for(int len = 0; len < m; len++) {
        for(int t = 0; t < 2; t++) {
            for(int last = 0; last <= 9; last++) {
                for(int s = 0; s < 2; s++) {
                    long long state = dp[len][t][last][s];
                    if(!state) continue;

                    int lim = t ? d[len] : 9;
                    for(int dig = 0; dig <= lim; dig++) {
                        int nt = t && (dig == lim);
                        int ns = s || dig > 0;
                        if(s && dig == last) continue;
                        dp[len + 1][nt][dig][ns] += state;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int t = 0; t < 2; t++) {
        for(int last = 0; last < 10; last++) {
            for(int s = 0; s < 2; s++) {
                ans += dp[m][t][last][s];
            }
        }
    }
    debug(n, ans);
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    long long a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a - 1) << '\n';

    return 0;
}
