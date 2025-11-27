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

const int inf = 1e9;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m));
    pair<int, int> start;

    vector<pair<int, int>> monsters;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'A') start = {i, j};
            if(s[j] == 'M') {
                monsters.emplace_back(i, j);
            }
            g[i][j] = s[j] != '#';
        }
    }

    vector<pair<int, int>> q;
    vector<vector<int>> dist_monsters(n, vector<int>(m, inf));

    for(auto &[r, c] : monsters) {
        q.emplace_back(r, c);
        dist_monsters[r][c] = 0;
    }

    // multi bfs
    for(int i = 0; i < (int)q.size(); i++) {
        auto [r, c] = q[i];
        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || !g[nr][nc] || dist_monsters[nr][nc] < inf) continue;
            dist_monsters[nr][nc] = dist_monsters[r][c] + 1;
            q.emplace_back(nr, nc);
        }
    }

    // normal bfs (need to avoid cells with lower monster distances)
    vector<vector<int>> dist(n, vector<int>(m, inf));
    vector<vector<int>> pv(n, vector<int>(m, -1));
    q.assign(1, start);
    dist[start.first][start.second] = 0;

    for(int i = 0, found = 0; i < (int)q.size() && !found; i++) {
        auto [r, c] = q[i];

        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || !g[nr][nc] || dist[nr][nc] < inf) continue;

            int nd = dist[r][c] + 1;
            if(nd >= dist_monsters[nr][nc]) continue;

            q.emplace_back(nr, nc);
            dist[nr][nc] = dist[r][c] + 1;
            pv[nr][nc] = d;
        }
    }

    pair<int, int> end = {-1, -1};

    for(int i = 0; i < n; i++) {
        if(dist[i][0] < inf) {
            end = {i, 0};
            break;
        }
        if(dist[i][m - 1] < inf) {
            end = {i, m - 1};
            break;
        }
    }
    for(int j = 0; j < m; j++) {
        if(dist[0][j] < inf) {
            end = {0, j};
            break;
        }
        if(dist[n - 1][j] < inf) {
            end = {n - 1, j};
            break;
        }
    }

    if(end == make_pair(-1, -1)) {
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
