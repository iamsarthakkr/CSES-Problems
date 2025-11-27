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
int rdr[] = {1, 0, -1, 0};
int rdc[] = {0, -1, 0, 1};

char dir[] = {'U', 'R', 'D', 'L'};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    pair<int, int> start, end;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'A') start = {i, j};
            if(s[j] == 'B') end = {i, j};
            g[i][j] = s[j] != '#';
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<int>> pv(n, vector<int>(m, -1));

    vector<pair<int, int>> q;
    q.emplace_back(start);
    dist[start.first][start.second] = 0;

    for(int i = 0, found = 0; i < (int)q.size() && !found; i++) {
        auto [r, c] = q[i];

        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || !g[nr][nc] || dist[nr][nc] >= 0) continue;

            q.emplace_back(nr, nc);
            dist[nr][nc] = dist[r][c] + 1;
            pv[nr][nc] = d;

            if(end == make_pair(nr, nc)) {
                found = 1;
                break;
            }
        }
    }

    if(dist[end.first][end.second] == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    string path;
    pair<int, int> cur = end;
    while(pv[cur.first][cur.second] != -1) {
        auto [i, j] = cur;
        int d = pv[i][j];
        path.push_back(dir[d]);
        cur = {i + rdr[d], j + rdc[d]};
    }
    reverse(path.begin(), path.end());

    cout << "YES" << '\n';
    cout << (int)path.size() << '\n';
    cout << path << '\n';

    return 0;
}
