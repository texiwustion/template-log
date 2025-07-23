using i64 = long long;
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b >>= 1, a *= a) {
        if (b & 1) res *= a;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt(): x{} {}
    constexpr MInt(i64 x): x(norm(x % P)) {}
    constexpr int norm(int x) {
        if (x < 0) x += P;
        if (x >= P) x -= P;
        return x;
    }
    constexpr MInt inv() {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator+=(MInt rhs) &{
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) &{
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator*=(MInt rhs) &{
        x = 1ll * x * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) &{
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        return res += rhs;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        return res -= rhs;
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        return res *= rhs;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        return res /= rhs;
    }
    friend constexpr istream &operator>>(istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MInt &a) {
        os << a.x;
        return os;
    }
};
constexpr int P = 1e9 + 7;
using Z = MInt<P>;