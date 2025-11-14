#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while(a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename VarMod>
class ModInt {
  public:
    using Type = typename decay<decltype(VarMod::value)>::type;

  public:
    ModInt() : v(0) {}

    template <typename T>
    ModInt(T v_) {
        v = normalize(v_);
    }

    static const Type mod() { return VarMod::value; }

    const Type &operator()() const { return v; }
    template <typename U> explicit operator U() const { return static_cast<U>(v); }

    ModInt &operator+=(const ModInt &other) {
        v = normalize((int64_t)v + (int64_t)other.v);
        return *this;
    }
    ModInt &operator-=(const ModInt &other) {
        v = normalize((int64_t)v - (int64_t)other.v);
        return *this;
    }
    ModInt &operator*=(const ModInt &other) {
        v = normalize((int64_t)v * (int64_t)other.v);
        return *this;
    }
    ModInt &operator/=(const ModInt &other) {
        *this *= ModInt(inverse(other.v, mod()));
        return *this;
    }

    template <typename U> ModInt &operator+=(const U &other) { return *this += ModInt(other); }
    template <typename U> ModInt &operator-=(const U &other) { return *this -= ModInt(other); }
    template <typename U> ModInt &operator*=(const U &other) { return *this *= ModInt(other); }
    template <typename U> ModInt &operator/=(const U &other) { return *this /= ModInt(other); }

    ModInt &operator++() { return *this += 1; }
    ModInt &operator--() { return *this -= 1; }

    ModInt operator++(int) {
        ModInt result(*this);
        *this += 1;
        return result;
    }
    ModInt operator--(int) {
        ModInt result(*this);
        *this -= 1;
        return result;
    }

    ModInt operator+() const { return ModInt(v); }
    ModInt operator-() const { return ModInt(-v); }

    friend ModInt operator+(const ModInt &a, const ModInt &b) { return ModInt(a) += b; }
    friend ModInt operator-(const ModInt &a, const ModInt &b) { return ModInt(a) -= b; }
    friend ModInt operator*(const ModInt &a, const ModInt &b) { return ModInt(a) *= b; }
    friend ModInt operator/(const ModInt &a, const ModInt &b) { return ModInt(a) /= b; }

    template <typename U> friend ModInt operator+(const ModInt &a, const U &b) { return ModInt(a) += b; }
    template <typename U> friend ModInt operator-(const ModInt &a, const U &b) { return ModInt(a) -= b; }
    template <typename U> friend ModInt operator*(const ModInt &a, const U &b) { return ModInt(a) *= b; }
    template <typename U> friend ModInt operator/(const ModInt &a, const U &b) { return ModInt(a) /= b; }

    template <typename U> friend ModInt operator+(const U &a, const ModInt &b) { return ModInt(a) += b; }
    template <typename U> friend ModInt operator-(const U &a, const ModInt &b) { return ModInt(a) -= b; }
    template <typename U> friend ModInt operator*(const U &a, const ModInt &b) { return ModInt(a) *= b; }
    template <typename U> friend ModInt operator/(const U &a, const ModInt &b) { return ModInt(a) /= b; }

    friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
    friend bool operator!=(const ModInt &a, const ModInt &b) { return !(a == b); }

    template <typename U> friend bool operator==(const ModInt &a, const U &b) { return a.v == ModInt(b); }
    template <typename U> friend bool operator==(const U &a, const ModInt &b) { return ModInt(a) == b; }

    template <typename U> friend bool operator!=(const ModInt &a, const U &b) { return a.v != ModInt(b); }
    template <typename U> friend bool operator!=(const U &a, const ModInt &b) { return ModInt(a) != b; }

    friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
    template <typename U> friend bool operator<(const ModInt &a, const U &b) { return a < ModInt(b); }
    template <typename U> friend bool operator<(const U &a, const ModInt &b) { return ModInt(a) < b; }

    friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
    template <typename U> friend bool operator<=(const ModInt &a, const U &b) { return a <= ModInt(b); }
    template <typename U> friend bool operator<=(const U &a, const ModInt &b) { return ModInt(a) <= b; }

    friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
    template <typename U> friend bool operator>(const ModInt &a, const U &b) { return a > ModInt(b); }
    template <typename U> friend bool operator>(const U &a, const ModInt &b) { return ModInt(a) > b; }

    friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }
    template <typename U> friend bool operator>=(const ModInt &a, const U &b) { return a >= ModInt(b); }
    template <typename U> friend bool operator>=(const U &a, const ModInt &b) { return ModInt(a) >= b; }

    friend std::ostream &operator<<(std::ostream &out, const ModInt &n) { return out << Type(n); }
    friend std::istream &operator>>(std::istream &in, ModInt &n) {
        int64_t v_;
        in >> v_;
        n = ModInt(v_);
        return in;
    }

  private:
    template <typename T>
    static Type normalize(T x) {
        Type v = static_cast<Type>(x % mod());

        if(v < 0) v += mod();
        return v;
    }

  private:
    Type v;
};

template <typename T, typename U>
T power(const T &base, const U &exp) {
    assert(exp >= 0);
    T x = base, res = 1;
    U p = exp;
    while(p > 0) {
        if(p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
std::string to_string(const ModInt<T> &number) {
    return to_string(number());
}

/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value = 1000000007;
ModType& md = VarMod::value;

using Mint = ModInt<VarMod>;
*/

constexpr int md = 1000000007;
using Mint = ModInt<std::integral_constant<decay<decltype(md)>::type, md>>;

/*
std::vector<Mint> fact(1, 1);
std::vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
    if (k < 0 || k > n) return 0;

    while((int)fact.size() < n + 1) {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/

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

    void init(int n, Node val = Node::id()) {
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
struct SumNode {
    T sum;
    constexpr SumNode() noexcept : sum(0) {}
    constexpr SumNode(const T &v) noexcept : sum(v) {}

    static constexpr SumNode id() noexcept { return SumNode(); }
    static constexpr SumNode merge(const SumNode &a, const SumNode &b) noexcept {
        return SumNode(a.sum + b.sum);
    }
};
template <typename T> using Segtree = SegtreeImpl<SumNode<T>>;

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

    vector<Mint> dp(n, 1);
    Segtree<Mint> st(2 * n, Mint(0));
    vector<Mint> cnt(n);

    for(int i = n - 1; i >= 0; --i) {
        dp[i] += st.calc(a[i] + 1, n + 1).sum;
        cnt[a[i]] += dp[i];
        st.set(a[i], cnt[a[i]]);
    }

    Mint ans = 0;
    for(int i = 0; i < n; i++) ans += dp[i];

    cout << ans << '\n';

    return 0;
}
