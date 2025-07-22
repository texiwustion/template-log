using i64 = long long;
struct LinearBasis {
    int num;//线性基中元素个数
    i64 d[60+5];//线性基
    i64 p[60+5];//查询第k小时的改造的线性基
    int cnt;//改造线性基用
    LinearBasis() {
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        num=0;
        cnt=0;
    }
    bool add(i64 x){
        for(int i=60; i>=0; i--) {
            if(x&(1LL<<i)) {
                if(d[i])//插入失败，异或
                    x^=d[i];
                else {//插入成功，保存后退出
                    num++;//统计线性基中元素个数
                    d[i]=x;
                    break;
                }
            }
        }
        return x>0;//x>0插入成功
    }
    i64 queryMax() {//查询最大值
        i64 res=0;
        for(int i=60; i>=0; i--)
            if((res^d[i])>res)
                res^=d[i];
        return res;
    }
    i64 queryMin() {//查询最小值
        for(int i=0; i<=60; i++)
            if(d[i])
                return d[i];
        return 0;
    }
    void rebuild() {//改造线性基
        for(int i=60; i>=0; i--)
            for(int j=i-1; j>=0; j--)
                if(d[i]&(1LL<<j))
                    d[i]^=d[j];
        for(int i=0; i<=60; i++)
            if(d[i])
                p[cnt++]=d[i];
    }
    i64 queryKth(i64 k) {//查询第k小的值，若要查k大，将k换为n-k+1即可
        int res=0;
        if (k>=(1LL<<cnt))
            return -1;
        for (int i=60; i>=0; i--)
            if (k&(1LL<<i))
                res^=p[i];
        return res;
    }
};
LinearBasis Union(const LinearBasis &rhs1,const LinearBasis &rhs2) {
    LinearBasis res=rhs1;
    for(int i=60; i>=0; i--)
        if(rhs2.d[i])
            res.add(rhs1.d[i]);
    return res;
}