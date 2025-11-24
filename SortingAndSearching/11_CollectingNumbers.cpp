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

    vector<int> a(n), pos(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(pos[i] < pos[i - 1]) ans++;
    }
    cout << ans << '\n';

    return 0;
}
