#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) g[i][j] = s[j] == '.';
    }

    debug(g);

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    auto valid = [&](int i, int j) { return i >= 0 && i < n && j >= 0 && j < m && g[i][j]; };

    int cnt = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
        vis[i][j] = 1;

        for(int d = 0; d < 4; d++) {
            int ni = i + dr[d], nj = j + dc[d];
            if(valid(ni, nj) && !vis[ni][nj]) dfs(ni, nj);
        }
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] && !vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}
