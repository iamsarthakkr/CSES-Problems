#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

namespace mint {
template <typename T> T inverse(T a, T m) {
    T u = 0, v = 1;
    T mod = m;
    while(a != 0) {
        T t = m / a;
        m -= t * a;
        std::swap(a, m);
        u -= t * v;
        std::swap(u, v);
    }
    assert(m == 1);
    if(u < 0) u += mod;
    return u;
}

template <typename T, typename U> T power(T base, U exp) {
    assert(exp >= 0);
    T res = 1;
    while(exp > 0) {
        if(exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

template <typename VarMod>
class ModInt {
  public:
    using Type = typename std::decay<decltype(VarMod::value)>::type;

    ModInt() : val(0) {}
    template <typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    ModInt(T x) : val(normalize(x)) {}

    static Type mod() { return VarMod::value; }

    const Type &operator()() const { return val; }
    template <typename U> explicit operator U() const { return static_cast<U>(val); }

    ModInt &operator+=(const ModInt &other) {
        val = normalize((int64_t)val + (int64_t)other.val);
        return *this;
    }
    ModInt &operator-=(const ModInt &other) {
        val = normalize((int64_t)val - (int64_t)other.val);
        return *this;
    }
    ModInt &operator*=(const ModInt &other) {
        val = normalize((int64_t)val * (int64_t)other.val);
        return *this;
    }
    ModInt &operator/=(const ModInt &other) {
        *this *= ModInt(inverse(other.val, mod()));
        return *this;
    }

    // compound ops with arithmetic types
    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    ModInt &operator+=(U other) { return *this += ModInt(other); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    ModInt &operator-=(U other) { return *this -= ModInt(other); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    ModInt &operator*=(U other) { return *this *= ModInt(other); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    ModInt &operator/=(U other) { return *this /= ModInt(other); }

    ModInt &operator++() { return *this += 1; }
    ModInt &operator--() { return *this -= 1; }

    ModInt operator++(int) {
        ModInt res(*this);
        *this += 1;
        return res;
    }
    ModInt operator--(int) {
        ModInt res(*this);
        *this -= 1;
        return res;
    }

    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(-val); }

    friend ModInt operator+(ModInt a, const ModInt &b) {
        a += b;
        return a;
    }
    friend ModInt operator-(ModInt a, const ModInt &b) {
        a -= b;
        return a;
    }
    friend ModInt operator*(ModInt a, const ModInt &b) {
        a *= b;
        return a;
    }
    friend ModInt operator/(ModInt a, const ModInt &b) {
        a /= b;
        return a;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator+(ModInt a, U b) {
        a += b;
        return a;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator-(ModInt a, U b) {
        a -= b;
        return a;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator*(ModInt a, U b) {
        a *= b;
        return a;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator/(ModInt a, U b) {
        a /= b;
        return a;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator+(U a, ModInt b) {
        b += a;
        return b;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator-(U a, ModInt b) {
        ModInt res(a);
        res -= b;
        return res;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator*(U a, ModInt b) {
        b *= a;
        return b;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend ModInt operator/(U a, ModInt b) {
        ModInt res(a);
        res /= b;
        return res;
    }

    friend bool operator==(const ModInt &a, const ModInt &b) { return a.val == b.val; }
    friend bool operator!=(const ModInt &a, const ModInt &b) { return a.val != b.val; }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator==(const ModInt &a, U b) { return a == ModInt(b); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator==(U a, const ModInt &b) { return ModInt(a) == b; }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator!=(const ModInt &a, U b) { return !(a == b); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator!=(U a, const ModInt &b) { return !(a == b); }

    friend bool operator<(const ModInt &a, const ModInt &b) { return a.val < b.val; }
    friend bool operator<=(const ModInt &a, const ModInt &b) { return a.val <= b.val; }
    friend bool operator>(const ModInt &a, const ModInt &b) { return a.val > b.val; }
    friend bool operator>=(const ModInt &a, const ModInt &b) { return a.val >= b.val; }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator<(const ModInt &a, U b) { return a < ModInt(b); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator<(U a, const ModInt &b) { return ModInt(a) < b; }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator<=(const ModInt &a, U b) { return a <= ModInt(b); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator<=(U a, const ModInt &b) { return ModInt(a) <= b; }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator>(const ModInt &a, U b) { return a > ModInt(b); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator>(U a, const ModInt &b) { return ModInt(a) > b; }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator>=(const ModInt &a, U b) { return a >= ModInt(b); }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
    friend bool operator>=(U a, const ModInt &b) { return ModInt(a) >= b; }

    friend std::ostream &operator<<(std::ostream &out, const ModInt &n) {
        return out << n.val;
    }

    friend std::istream &operator>>(std::istream &in, ModInt &n) {
        long long x;
        in >> x;
        n = ModInt(x);
        return in;
    }

  private:
    template <typename T>
    static Type normalize(T x) {
        Type m = mod();
        Type v = static_cast<Type>(x % m);
        if(v < 0) v += m;
        return v;
    }

    Type val;
};

template <typename VarMod>
std::string to_string(const ModInt<VarMod> &number) {
    return std::to_string(number());
}

/*
using ModType = int;
struct VarMod {
    static ModType value;
};
ModType VarMod::value = 1000000007;
ModType &md = VarMod::value;
using Mint = ModInt<VarMod>;
*/

constexpr int md = 1000000007;
using Mint = ModInt<std::integral_constant<int, md>>;

/*
static std::vector<Mint> fact(1, Mint(1));
static std::vector<Mint> inv_fact(1, Mint(1));
Mint C(int n, int k) {
    if(k < 0 || k > n) return Mint(0);
    while((int)fact.size() <= n) {
        int i = (int)fact.size();
        fact.emplace_back(fact.back() * i);
        inv_fact.emplace_back(Mint(1) / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/

} // namespace mint

using namespace mint;

const int inf = 2e9;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> indeg(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        indeg[v]++;
    }

    vector<int> order;
    for(int u = 0; u < n; u++) {
        if(indeg[u] == 0) order.emplace_back(u);
    }

    for(int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for(int v : g[u]) {
            if(--indeg[v] == 0) order.emplace_back(v);
        }
    }

    vector<Mint> dp(n);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int u = order[i];
        if(dp[u] == 0) continue;

        for(int v : g[u]) {
            dp[v] += dp[u];
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
