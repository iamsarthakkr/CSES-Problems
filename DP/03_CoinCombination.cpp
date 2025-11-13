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

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

const int SM = 1000001, N = 101;
int a[N];
long long dp[SM] = {0};

const long long MOD = ll(1e9) + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL);

    int n, S;
    cin >> n >> S;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    memset(dp, 0LL, sizeof(dp));
    dp[0] = 1;

    for(int s = 1; s <= S; s++) {
        for(int i = 1; i <= n; i++) {
            int ps = s - a[i - 1];
            if(ps >= 0) dp[s] += dp[ps];
            if(dp[s] >= MOD) dp[s] -= MOD;
        }
    }
    cout << dp[S] << '\n';

    debug(clock() / 1000);

    return 0;
}
