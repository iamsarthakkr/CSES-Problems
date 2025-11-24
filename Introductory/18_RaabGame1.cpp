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

    int tt;
    cin >> tt;
    while(tt--) {
        debug(tt);
        int n, a, b;
        cin >> n >> a >> b;
        int draws = n - (a + b);
        if(draws < 0) {
            cout << "NO" << '\n';
            continue;
        }

        vector<int> first, second;
        for(int x = 1; x <= draws; x++) first.push_back(x), second.push_back(x);
        for(int i = 0; i < a; i++) {
            first.push_back(n - a + i + 1);
            second.push_back(draws + i + 1);
        }
        for(int i = 0; i < b; i++) {
            second.push_back(n - b + i + 1);
            first.push_back(draws + i + 1);
        }
        int v1 = 0, v2 = 0;
        for(int i = 0; i < n; i++) {
            v1 += first[i] > second[i];
            v2 += first[i] < second[i];
        }
        if(v1 != a || v2 != b) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) cout << first[i] << " \n"[i == n - 1];
        for(int i = 0; i < n; i++) cout << second[i] << " \n"[i == n - 1];
    }

    return 0;
}
