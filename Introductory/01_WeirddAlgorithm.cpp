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

    long long n;
    cin >> n;

    while(true) {
        cout << n << ' ';
        if(n == 1) break;
        if(n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }

    return 0;
}
