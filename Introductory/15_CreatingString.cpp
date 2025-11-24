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

    vector<int> used(n);
    vector<string> res;
    function<void(string &)> solve = [&](string &str) {
        if((int)str.size() == n) {
            res.emplace_back(str);
        }
        for(int i = 0; i < n; i++) {
            if(!used[i]) {
                str.push_back(s[i]);
                used[i] = 1;
                solve(str);
                str.pop_back();
                used[i] = 0;
            }
        }
    };

    string foo;
    solve(foo);

    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());

    cout << (int)res.size() << '\n';
    for(const string &a : res) cout << a << "\n";

    return 0;
}
