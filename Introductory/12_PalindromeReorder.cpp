#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const int N = 26;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> cnt(N);
    for(char c : s) cnt[c - 'A']++;

    int od = 0;
    for(int i = 0; i < N; i++) od += cnt[i] & 1;

    if(od >= 2 || (n % 2 == 0 && od >= 1)) {
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    string left, right;
    char mid = ' ';

    for(int i = 0; i < N; i++) {
        for(int c = 0; c < cnt[i] / 2; c++) left.push_back(char('A' + i)), right.push_back(char('A' + i));
        if(cnt[i] & 1) mid = 'A' + i;
    }

    if(mid != ' ') left += mid;

    reverse(right.begin(), right.end());

    cout << left + right << '\n';

    return 0;
}
