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

const int MOD = (int)1e9 + 7;
const int alpha = 26;

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n, m;
    string s;
    cin >> s >> m;
    n = len(s);
    vector<string> a(m);
    forn(i, m) cin >> a[i];

    vvi trie(1, vi(alpha, -1));
    vi cnt(1, 0);

    trie.reserve(1e6);
    cnt.reserve(1e6);

    auto Add = [&](const string &t) {
        int id = 0;
        forv(c, t) {
            int v = c - 'a';
            if(trie[id][v] == -1) {
                trie[id][v] = (int)trie.size();
                trie.emplace_back(vi(alpha, -1));
                cnt.emplace_back(0);
            }
            id = trie[id][v];
        }
        cnt[id]++;
    };

    auto Count = [&](int l, int r) -> int {
        int id = 0;
        for(int i = l; i < r; i++) {
            int v = s[i] - 'a';
            if(trie[id][v] == -1) {
                return 0;
            }
            id = trie[id][v];
        }
        return cnt[id];
    };

    debug(clock() / 1000);

    forv(t, a) if(len(t) <= n) Add(t);
    debug(clock() / 1000);

    vector<ll> dp(n + 1);
    dp[n] = 1;
    for(int l = n - 1; l >= 0; --l) {
        int id = 0, cur = 0;

        for(int r = l + 1; r <= n; r++) {
            int v = s[r - 1] - 'a';
            if(trie[id][v] == -1) {
                cur = 0;
                break;
            }

            id = trie[id][v];
            dp[l] = (dp[l] + dp[r] * cnt[id]) % MOD;
        }
    }
    cout << dp[0] << '\n';
    debug(clock() / 1000);

    return 0;
}
