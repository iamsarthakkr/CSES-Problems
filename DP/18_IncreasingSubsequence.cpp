#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

template <typename Node> class SegtreeImpl {
  public:
    explicit SegtreeImpl(int n) { init(n); }
    template <typename T> explicit SegtreeImpl(int n, T val) { init(n, val); }
    explicit SegtreeImpl(const std::vector<Node> &info) : SegtreeImpl((int)info.size()) { build(1, 0, m_size, info); }
    template <typename T>
    explicit SegtreeImpl(const std::vector<T> &info) : SegtreeImpl((int)info.size()) { build(1, 0, m_size, info); }

    int size() const { return m_origSize; }

    void set(int i, const Node &v) { setImpl(1, 0, m_size, i, v); }

    Node get(int i) { return getImpl(i); }

    Node get() const { return m_tree[1]; }

    Node calc(int l, int r) {

        assert(0 <= l && l <= r && r <= m_origSize);
        if(l == r) return Node::id();
        return calcImpl(1, 0, m_size, l, r);
    }

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

    void init(int n, int val = Node::id()) {
        m_origSize = n;
        m_size = 1;
        while(m_size < n) m_size <<= 1;
        m_tree.resize(2 * m_size, val);
    }

    template <typename T>
    void build(int node, int lx, int rx, const std::vector<T> &arr) {
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
    std::vector<Node> m_tree;
};

template <typename T>
struct MaxNode {
    T mx;
    constexpr MaxNode() noexcept : mx(std::numeric_limits<T>::lowest()) {}
    constexpr MaxNode(const T &v) noexcept : mx(v) {}

    static constexpr MaxNode id() noexcept { return MaxNode(); }
    static constexpr MaxNode merge(const MaxNode &a, const MaxNode &b) noexcept {
        return MaxNode(a.mx < b.mx ? b.mx : a.mx);
    }
};
template <typename T> using Segtree = SegtreeImpl<MaxNode<T>>;

void compress(vector<int> &a) {
    int n = (int)a.size();

    vector<int> all = a;
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    for(int i = 0; i < n; i++) {
        a[i] = int(lower_bound(all.begin(), all.end(), a[i]) - all.begin());
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    compress(a);

    vector<int> dp(n, 0);
    Segtree<int> st(2 * n, 0);

    for(int i = 0; i < n; i++) debug(i, st.get(i).mx);

    for(int i = n - 1; i >= 0; --i) {
        dp[i] = 1 + st.calc(a[i] + 1, n + 1).mx;
        st.set(a[i], dp[i]);
    }
    debug(a);
    debug(dp);

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
