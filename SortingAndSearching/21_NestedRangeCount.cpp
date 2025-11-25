#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

template <typename T>
class fenwick {
  public:
    fenwick() : m_size(0) {}

    explicit fenwick(int n, T v = T{}) : m_size(n), m_fenwick(n, T{}) {
        if(v != T{}) {
            for(int i = 0; i < m_size; ++i) update(i, v);
        }
    }

    template <typename U>
    explicit fenwick(const std::vector<U> &a) : m_size(static_cast<int>(a.size())), m_fenwick(m_size, T{}) {
        for(int i = 0; i < m_size; ++i) {
            m_fenwick[i] += static_cast<T>(a[i]);
            int j = i | (i + 1);
            if(j < m_size) m_fenwick[j] += m_fenwick[i];
        }
    }

    // add v at index i (0-based)
    void update(int i, T v) {
        for(int j = i; j < m_size; j = j | (j + 1))
            m_fenwick[j] += v;
    }

    // prefix sum [0..r]
    T pref(int r) const {
        if(r < 0) return T{};
        T res{};
        for(int i = r; i >= 0; i = ((i & (i + 1)) - 1))
            res += m_fenwick[i];
        return res;
    }

    // range sum [l..r]
    T get(int l, int r) const {
        if(l > r) return T{};
        return pref(r) - pref(l - 1);
    }

    int size() const { return m_size; }

  private:
    int m_size;
    std::vector<T> m_fenwick;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    {
        // compress
        vector<int> all;
        for(int x : l) all.push_back(x);
        for(int x : r) all.push_back(x);

        sort(all.begin(), all.end());
        all.resize(unique(all.begin(), all.end()) - all.begin());

        for(int &x : l) x = int(lower_bound(all.begin(), all.end(), x) - all.begin());
        for(int &x : r) x = int(lower_bound(all.begin(), all.end(), x) - all.begin());
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    {
        // contains other

        sort(order.begin(), order.end(), [&](int i, int j) {
            if(r[i] == r[j]) return l[i] > l[j];
            return r[i] < r[j];
        });

        fenwick<int> fw(2 * n + 1);
        vector<int> cnt(n);
        for(int i : order) {
            cnt[i] = fw.get(l[i], r[i]);

            fw.update(l[i], +1);
        }

        for(int i = 0; i < n; i++) cout << cnt[i] << " \n"[i == n - 1];
    }

    {
        // contained by other

        sort(order.begin(), order.end(), [&](int i, int j) {
            if(l[i] == l[j]) return r[i] > r[j];
            return l[i] < l[j];
        });

        fenwick<int> fw(2 * n + 1);
        vector<int> cnt(n);
        for(int i : order) {
            cnt[i] = fw.get(r[i], 2 * n);

            fw.update(r[i], +1);
        }

        for(int i = 0; i < n; i++) cout << cnt[i] << " \n"[i == n - 1];
    }
    return 0;
}
