#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

int get(long long v, int d) {
    return to_string(v)[d - 1] - '0';
}

const int L = 18;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int tt;
    cin >> tt;

    vector<long long> p10(L);
    p10[0] = 1;
    for(int l = 1; l < L; l++) p10[l] = p10[l - 1] * 10;

    while(tt--) {
        long long n;
        cin >> n;

        int len = 1;
        while(true) {
            long long avail = len * 9 * p10[len - 1];

            if(avail < n) {
                n -= avail;
                len++;
                continue;
            }

            debug(len, n);

            long long mx = n / len;
            long long last = p10[len - 1] + max(0LL, (mx - 1)), rem = n - mx * len;

            if(rem == 0) {
                cout << get(last, len) << '\n';
            } else {
                cout << get(last + 1, (int)rem) << '\n';
            }
            break;
        }
    }

    return 0;
}
