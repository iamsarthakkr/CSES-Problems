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

    string s;
    cin >> s;
    int n = (int)s.size();

    int ans = 0;
    for(int i = 0; i < n;) {
        int j = i;
        while(j < n && s[i] == s[j]) j++;
        ans = max(ans, j - i);
        i = j;
    }

    cout << ans << '\n';

    return 0;
}
