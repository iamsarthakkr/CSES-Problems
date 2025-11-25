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

    vector<int> res(n);
    vector<int> s; // prefix stack in increasing order (strict)
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[s.back()] >= a[i]) s.pop_back();
        if(!s.empty()) res[i] = s.back() + 1;
        s.emplace_back(i);
    }
    for(int x : res) cout << x << " ";
    cout << '\n';

    return 0;
}
