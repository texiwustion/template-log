const int N = 1e3 + 7;
namespace binom {
    Z fac[N], ifac[N];
    int __ = []
    {
        fac[0] = 1;
        for (int i = 1; i <= N - 5; i++)
            fac[i] = fac[i - 1] * i;
        ifac[N - 5] =fac[N - 5].inv();
        for (int i = N - 5; i; i--)
            ifac[i - 1] = ifac[i] * i;
        return 0;
    }();

    inline Z C(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[m] * ifac[n - m];
    }

    inline Z A(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[n - m];
    }
}
using namespace binom;