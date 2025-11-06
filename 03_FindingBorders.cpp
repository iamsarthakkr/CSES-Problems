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

vector<int> lps(const string &s) {
    int n = (int)s.size();
    vi p(n, 0);
    for(int i = 1; i < n; i++) {
        int k = p[i - 1];
        while(k > 0 && s[k] != s[i]) k = p[k - 1];
        if(s[k] == s[i]) k++;
        p[i] = k;
    }

    return p;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    string s;
    cin >> s;
    int n = (int)s.size();

    auto p = lps(s);

    vi ans;
    int v = p[n - 1];
    while(v > 0) {
        if(s[v - 1] == s[n - 1]) ans.emplace_back(v);
        v = p[v - 1];
    }

    sort(all(ans));
    forv(x, ans) cout << x << " ";
    cout << '\n';

    return 0;
}
