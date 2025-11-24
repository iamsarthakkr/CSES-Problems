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
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long can = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > can + 1) {
            break;
        }
        can += a[i];
    }

    cout << can + 1 << '\n';

    return 0;
}
