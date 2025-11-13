#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < n; i++)
#define forv(x, a) for(auto &x : a)
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define forr(i, l, r) for(int i = l; i <= r; i++)
#define forrd(i, l, r) for(int i = r; i >= l; i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(a) (int)(a).size()
#define sq(x) (x) * (x)

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<pii>> pv(n + 1, vector<pii>(m + 1, {-1, -1}));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                pv[i][j] = make_pair(i - 1, j - 1);
            }

            else {
                if(cmax(dp[i][j], dp[i - 1][j])) pv[i][j] = make_pair(i - 1, j);
                if(cmax(dp[i][j], dp[i][j - 1])) pv[i][j] = make_pair(i, j - 1);
                if(cmax(dp[i][j], dp[i - 1][j - 1])) pv[i][j] = make_pair(i - 1, j - 1);
            }
        }
    }
    int len = dp[n][m];
    vi res;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i - 1] == b[j - 1]) {
            res.push_back(a[i - 1]);
        }
        auto p = pv[i][j];
        i = p.first, j = p.second;
    }

    reverse(res.begin(), res.end());
    cout << len << '\n';
    for(int x : res) cout << x << " ";
    cout << '\n';

    return 0;
}
