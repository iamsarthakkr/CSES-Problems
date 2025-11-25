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

    int n, k;
    cin >> n >> k;

    set<int> a;
    for(int x = 1; x <= n; x++) a.insert(x);

    fenwick<int> fw(n + 1);
    for(int i = 1; i <= n; i++) fw.update(i, +1);

    int cur = 1;
    vector<int> res;
    while(a.size() > 1) {
        int toSkip = k % (int)a.size();
        int tillEnd = fw.get(cur, n);
        if(tillEnd <= toSkip) {
            toSkip -= tillEnd;
            cur = *a.begin();
        }
        if(toSkip == 0) {
            res.push_back(cur);
            a.erase(cur);
            fw.update(cur, -1);

            auto it = a.lower_bound(cur);
            if(it == a.end()) it = a.begin();
            cur = *it;

            continue;
        }
        int lo = cur, hi = n;
        while(hi > lo + 1) {
            int m = (hi + lo) >> 1;
            if(fw.get(cur, m) <= toSkip) {
                lo = m;
            } else {
                hi = m;
            }
        }
        res.push_back(hi);
        a.erase(hi);
        fw.update(hi, -1);

        auto it = a.lower_bound(hi);
        if(it == a.end()) it = a.begin();
        cur = *it;
    }

    res.push_back(*a.begin());

    for(int x : res) cout << x << " ";
    cout << '\n';

    return 0;
}
