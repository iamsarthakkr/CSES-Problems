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

vector<int> kmp(const string &s) {
    int n = (int)s.size();
    vector<int> p(n + 1);
    p[0] = -1;

    for(int i = 1; i <= n; i++) {
        int k = p[i - 1];
        while(k >= 0 && s[k] != s[i - 1]) {
            k = p[k];
        }
        p[i] = k + 1;
    }

    return p;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    string s, t;
    cin >> s >> t;

    int n = len(s), m = len(t);

    string a = t + "#" + s;
    auto p = kmp(a);
    int ans = 0;

    forn(i, n) {
        if(p[m + i + 2] == m) ans++;
    }
    cout << ans << '\n';

    return 0;
}
