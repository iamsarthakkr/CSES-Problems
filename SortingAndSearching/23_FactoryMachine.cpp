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
    long long req;
    cin >> n >> req;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto good = [&](long long t) {
        long long made = 0;
        for(int per : a) made += t / per;
        return made >= req;
    };

    long long lo = 0, hi = 1;
    while(!good(hi)) hi <<= 1;
    while(hi > lo + 1) {
        long long m = (hi + lo) >> 1;
        if(good(m))
            hi = m;
        else
            lo = m;
    }
    cout << hi << '\n';

    return 0;
}
