#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    int m = 2 * n - 1;
    vector<vector<bool>> good(n, vector<bool>(n, 0));
    vector<vector<pair<int, int>>> diag(m);
    vector<vector<char>> avail(m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int id = i + j;
            diag[id].emplace_back(i, j);
            if(find(avail[id].begin(), avail[id].end(), g[i][j]) == avail[id].end()) {
                avail[id].emplace_back(g[i][j]);
            }
        }
    }

    string res(1, g[0][0]);
    good[0][0] = 1;

    while((int)res.size() < m) {
        int nx = (int)res.size();
        bool found = 0;
        sort(avail[nx].begin(), avail[nx].end());
        for(char c : avail[nx]) {
            for(auto &[i, j] : diag[nx]) {
                if(g[i][j] != c) continue;
                if(i > 0 && good[i - 1][j]) found = 1;
                if(j > 0 && good[i][j - 1]) found = 1;
            }
            if(found) {
                for(auto &[i, j] : diag[nx]) {
                    if(g[i][j] != c) continue;
                    if((i > 0 && good[i - 1][j]) || (j > 0 && good[i][j - 1])) {
                        good[i][j] = 1;
                    }
                }
                res.push_back(c);
                break;
            }
        }
        assert(found);
    }

    cout << res << '\n';

    debug(clock() / 1000);

    return 0;
}
