#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

template <typename Node> class SegtreeImpl {
  public:
    explicit SegtreeImpl(int n) { init(n); }
    explicit SegtreeImpl(const vector<Node> &info) : SegtreeImpl((int)info.size()) { build(1, 0, m_size, info); }
    template <typename T>
    explicit SegtreeImpl(const vector<T> &info) : SegtreeImpl((int)info.size()) { build(1, 0, m_size, info); }

    int size() const { return m_origSize; }

    void set(int i, const Node &v) { setImpl(1, 0, m_size, i, v); }

    Node get(int i) { return getImpl(i); }

    Node get() const { return m_tree[1]; }

    Node calc(int l, int r) { return calcImpl(1, 0, m_size, l, r); }

    template <class F>
    void update(int i, F fn) { set(i, fn(get(i))); }

    template <typename F> int maxRight(int l, F pred, Node acc = Node::id()) {
        assert(pred(acc));
        return std::min(m_origSize, maxRightImpl(1, 0, m_size, l, pred, acc));
    };

    template <typename F> int minLeft(int r, F pred, Node acc = Node::id()) {
        assert(pred(acc));
        return std::max(0, minLeftImpl(1, 0, m_size, r, pred, acc));
    };

  private:
    void setImpl(int node, int lx, int rx, int i, const Node &v) {
        if(rx - lx == 1) {
            m_tree[node] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if(i < m)
            setImpl(node << 1, lx, m, i, v);
        else
            setImpl(node << 1 | 1, m, rx, i, v);

        recalc(node);
    }

    Node getImpl(int i) {
        int node = 1, lx = 0, rx = m_size;
        while(rx - lx > 1) {
            int m = (lx + rx) >> 1;
            if(i < m)
                rx = m, node = node << 1;
            else
                lx = m, node = node << 1 | 1;
        }
        return m_tree[node];
    }

    Node calcImpl(int node, int lx, int rx, int l, int r) {
        if(rx <= l || r <= lx) return Node::id();
        if(l <= lx && rx <= r) return m_tree[node];
        int m = (lx + rx) >> 1;
        auto s1 = calcImpl(node << 1, lx, m, l, r);
        auto s2 = calcImpl(node << 1 | 1, m, rx, l, r);
        return Node::merge(s1, s2);
    }

    template <typename F> int maxRightImpl(int node, int lx, int rx, int l, F &pred, Node &acc) {
        if(rx <= l) return l;
        if(l <= lx) {
            Node res = Node::merge(acc, m_tree[node]);
            if(pred(res)) {
                acc = std::move(res);
                return rx;
            }
            if(rx - lx == 1) return lx;
        }
        if(rx - lx == 1) return l;

        int m = (lx + rx) >> 1;

        int r1 = maxRightImpl(node << 1, lx, m, l, pred, acc);
        if(r1 < m) return r1;
        return maxRightImpl(node << 1 | 1, m, rx, l, pred, acc);
    }
    template <typename F> int minLeftImpl(int node, int lx, int rx, int r, F &pred, Node &acc) {
        if(r <= lx) return r;
        if(rx <= r) {
            Node res = Node::merge(m_tree[node], acc);
            if(pred(res)) {
                acc = std::move(res);
                return lx;
            }
            if(rx - lx == 1) return rx;
        }
        if(rx - lx == 1) return r;

        int m = (lx + rx) >> 1;

        int l1 = minLeftImpl(node << 1 | 1, m, rx, r, pred, acc);
        if(l1 > m) return l1;
        return minLeftImpl(node << 1, lx, m, r, pred, acc);
    }

  private:
    void recalc(int node) {
        m_tree[node] = Node::merge(m_tree[node << 1], m_tree[node << 1 | 1]);
    }

    void init(int n) {
        m_origSize = n;
        m_size = 1;
        while(m_size < n) m_size <<= 1;
        m_tree.resize(2 * m_size, Node::id());
    }

    template <typename T>
    void build(int node, int lx, int rx, const vector<T> &arr) {
        if(rx - lx == 1) {
            if(lx < (int)arr.size()) m_tree[node] = arr[lx];
            return;
        }
        int m = (lx + rx) >> 1;
        build(node << 1, lx, m, arr);
        build(node << 1 | 1, m, rx, arr);

        recalc(node);
    }

  private:
    int m_size;
    int m_origSize;
    vector<Node> m_tree;
};

template <typename T>
struct MinNode {
    T mn;
    constexpr MinNode() noexcept : mn(std::numeric_limits<T>::max()) {}
    constexpr MinNode(const T &v) noexcept : mn(v) {}

    static constexpr MinNode id() noexcept { return MinNode(); }
    static constexpr MinNode merge(const MinNode &a, const MinNode &b) noexcept {
        return MinNode(a.mn < b.mn ? a.mn : b.mn);
    }
};

using segtree = SegtreeImpl<MinNode<long long>>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, mn, mx;
    cin >> n >> mn >> mx;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<long long> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    segtree st(pref);

    // max pref[r] - pref[l - 1] with l in a certain range
    // for fixed r, we need min pref[l - 1]

    long long ans = -9e18;
    for(int r = 1; r <= n; r++) {
        // max l: r - l + 1 = mn => l = r - mn + 1
        // min l: r - l + 1 = mx => l = r - mx + 1
        int mn_l = max(1, r - mx + 1);
        int mx_l = r - mn + 1;
        if(mx_l < 1) continue;
        // we need min pref sum from mn_l to mx_l

        ans = max(ans, pref[r] - st.calc(mn_l - 1, mx_l).mn);
    }

    cout << ans << '\n';

    return 0;
}
