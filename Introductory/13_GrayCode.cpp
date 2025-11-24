#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

vector<string> solve(int n) {
    if(n == 0) return {""};

    auto prev = solve(n - 1);

    vector<string> res;
    bool flag = 1;
    for(const string &x : prev) {
        string y1 = x + "0", y2 = x + "1";
        if(flag) {
            res.emplace_back(y1);
            res.emplace_back(y2);
        } else {
            res.emplace_back(y2);
            res.emplace_back(y1);
        }
        flag ^= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n;
    cin >> n;

    auto res = solve(n);

    for(auto &x : res) cout << x << '\n';
    cout << '\n';

    return 0;
}
