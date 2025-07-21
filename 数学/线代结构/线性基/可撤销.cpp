/* ---------- 线性基：原地插入 + 撤销 ---------- */
struct LB {
    static constexpr int W = 60;          // 1e18 < 2^60
    ull b[W]{};

    // 返回 {是否真插入, 被改动的 bit 位}
    pair<bool,int> insert(ull x){
        for(int i=W-1;i>=0;--i) if(x>>i & 1){
            if(!b[i]){ b[i]=x; return {true,i}; }
            x ^= b[i];
        }
        return {false,-1};
    }
    void undo(int p){ if(p!=-1) b[p]=0; }

    ull max_xor() const{
        ull res = 0;
        for(int i=W-1;i>=0;--i) res = max(res, res ^ b[i]);
        return res;
    }
};