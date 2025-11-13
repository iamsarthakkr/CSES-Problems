#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < n; i++)
#define forv(x, a) for(auto &x : a)
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define forr(i, l, r) for(int i = l; i <= r; i++)
#define forrd(i, l, r) for(int i = r; i >= l; i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(a) (int)(a).size()
#define sq(x) (x) * (x)

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

const int x1 = 37;
const int x2 = 79;

using Hash = pair<vector<Mint>, const int>;

Hash createHash(const string &s, const int x) {
    int n = len(s);
    vector<Mint> h(n + 1);

    Mint px = 1;
    for(int i = 1; i <= n; i++) {
        h[i] = h[i - 1] + int(s[i - 1] - 'a') * px;
        px *= x;
    }
    return {h, x};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    string s;
    cin >> s;
    int n = len(s);

    auto hash1 = createHash(s, x1);
    auto hash2 = createHash(s, x2);

    auto inv1 = Mint(1) / x1;
    auto inv2 = Mint(1) / x2;

    vector<Mint> p1(n + 1), p2(n + 1);
    vector<Mint> inv_p1(n + 1), inv_p2(n + 1);
    forn(i, n) p1[i + 1] = power(Mint(x1), i + 1), p2[i + 1] = power(Mint(x2), i + 1);
    forn(i, n) inv_p1[i + 1] = power(inv1, i + 1), inv_p2[i + 1] = power(inv2, i + 1);

    auto Get = [&](const Hash &h, int l, int r) -> Mint {
        auto &p = h.first;
        auto &x = h.second;

        auto inv = x == x1 ? inv_p1[l + 1] : inv_p2[l + 1];

        return (p[r + 1] - p[l]) * inv;
    };
    vi good(n + 1);

    for(int l = 1; l <= n; l++) {
        bool fail = 0;
        if(good[l]) {
            cout << l << " ";
            continue;
        }

        auto v1 = Get(hash1, 0, l - 1);
        auto v2 = Get(hash2, 0, l - 1);

        for(int i = l; i < n; i += l) {
            int from = i, to = min(n - 1, i + l - 1);
            if(to - from + 1 < l) {
                auto h1 = Get(hash1, from, to), h2 = Get(hash2, from, to);
                int len = to - from + 1;
                int rem = l - len;
                int pl = len, pr = len + rem - 1;

                h1 += Get(hash1, pl, pr) * p1[len];
                h2 += Get(hash2, pl, pr) * p2[len];
                if(h1 != v1 || h2 != v2) {
                    fail = 1;
                    break;
                }

            } else {
                auto h1 = Get(hash1, from, to), h2 = Get(hash2, from, to);
                if(h1 != v1 || h2 != v2) {
                    fail = 1;
                    break;
                }
            }
        }
        if(!fail) {
            for(int x = l; x <= n; x += l) good[x] = 1;
            cout << l << " ";
        }
    }
    cout << '\n';
    debug(clock() / 1000);

    return 0;
}
