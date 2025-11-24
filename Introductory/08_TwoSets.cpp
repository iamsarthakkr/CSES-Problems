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

    long long tot = 1LL * n * (n + 1) / 2;

    if(tot & 1) {
        cout << "NO" << '\n';
        return 0;
    }
    long long req = tot / 2;

    vector<int> take(n + 1, 0);

    long long cs = 0;
    int cnt = 0;
    for(int x = 1; x <= n; x++) {
        cs += x;
        take[x] = 1;
        cnt++;

        if(cs == req) break;
        if(cs > req) {
            int y = int(cs - req);
            assert(take[y]);
            take[y] = 0;
            cs -= y;
            cnt--;
        }
    }
    assert(cs == req);

    cout << "YES" << '\n';
    cout << cnt << '\n';
    for(int x = 1; x <= n; x++)
        if(take[x]) cout << x << " ";
    cout << '\n';

    cout << n - cnt << '\n';
    for(int x = 1; x <= n; x++)
        if(!take[x]) cout << x << " ";
    cout << '\n';

    return 0;
}
