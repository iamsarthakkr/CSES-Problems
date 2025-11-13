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

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n;
    cin >> n;

    int m = n * (n + 1) / 2;

    if(m & 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<Mint> dp(m + 1), ndp(m + 1);
    dp[0] = 1;

    for(int x = 1; x <= n; x++) {
        fill(ndp.begin(), ndp.end(), 0);

        for(int s = 0; s <= m; s++) {
            ndp[s] += dp[s];
            if(s - x >= 0) ndp[s] += dp[s - x];
        }
        dp.swap(ndp);
    }

    cout << dp[m / 2] / 2 << '\n';

    return 0;
}
