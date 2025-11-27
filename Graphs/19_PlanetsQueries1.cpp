#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const int LOG = 30;
const int N = 200001;
int jump[N][LOG + 1];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, q;
    cin >> n >> q;
    vector<int> nxt(n);
    for(int i = 0; i < n; i++) {
        cin >> nxt[i];
        --nxt[i];
    }

    for(int i = 0; i < n; i++) jump[i][0] = nxt[i];

    for(int k = 1; k <= LOG; k++) {
        for(int i = 0; i < n; i++) {
            jump[i][k] = jump[jump[i][k - 1]][k - 1];
        }
    }

    while(q--) {
        int x, k;
        cin >> x >> k;
        --x;
        for(int j = LOG; j >= 0; j--) {
            int del = 1 << j;
            if(del <= k) {
                k -= del;
                x = jump[x][j];
            }
        }
        cout << x + 1 << '\n';
    }

    return 0;
}
