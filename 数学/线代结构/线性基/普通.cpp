#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct XORBasis {
    static constexpr int W = 64;
    unsigned long long b[W]{};              // b[i] 最高位 == i
    bool insert(unsigned long long x) {
        for (int i = W - 1; i >= 0; --i) if (x >> i & 1) {
            if (!b[i]) { b[i] = x; return true; }
            x ^= b[i];
        }
        return false;
    }
    unsigned long long max_xor() const {    // 空集允许，初始化 0
        unsigned long long res = 0;
        for (int i = W - 1; i >= 0; --i)
            res = std::max(res, res ^ b[i]);
        return res;
    }
    unsigned long long min_pos_xor() const { // 非空最小
        unsigned long long tmp[W]{};
        int idx = 0;
        for (int i = 0; i < W; ++i) if (b[i]) tmp[idx++] = b[i];
        if (!idx) return 0;                 // 没有非零向量
        // 高位升序
        for (int i = idx - 1; i >= 0; --i)
            for (int j = i - 1; j >= 0; --j)
                tmp[i] = std::min(tmp[i], tmp[i] ^ tmp[j]);
        unsigned long long ans = tmp[0];
        for (int i = 1; i < idx; ++i) ans = std::min(ans, tmp[i]);
        return ans;
    }
};


signed main() {
    std::cin.tie(0)->sync_with_stdio(0);
    XORBasis lb;
    for (auto x : {1, 3, 5}) lb.insert(x);
    cout << lb.max_xor() << '\n';//7=5^3^1
    cout << lb.min_pos_xor() << '\n';//最小正异或和 1
}