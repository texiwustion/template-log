//https://www.cnblogs.com/bianchengmao/p/16713133.html
const int N = 1e5 + 7;
struct PrefixLinearBasis{
    int d[N][32];//前缀线性基
    int pos[N][32];//最后一个修改i这个位置的数
    int num;//线性基中元素个数
    PrefixLinearBasis(){
        memset(d,0,sizeof(d));
        memset(pos,0,sizeof(pos));
        num=0;
    }
    void clear(){
        memset(d,0,sizeof(d));
        memset(pos,0,sizeof(pos));
        num=0;
    }
    void add(int x){//向线性基中添加x
        num++;
        for(int i=0; i<32; i++){//复制前num-1个线性基
            d[num][i]=d[num-1][i];
            pos[num][i]=pos[num-1][i];
        }

        int P=num;
        for(int i=31; i>=0; i--){
            if((x>>i)&1){
                if(d[num][i]){//插入失败
                    if(pos[num][i]<P){//交换位置
                        swap(pos[num][i], P);
                        swap(d[num][i],x);
                    }
                    x^=d[num][i];//异或
                }
                else{//插入成功
                    d[num][i]=x;
                    pos[num][i]=P;
                    break;
                }
            }
        }
    }
    int queryMax(int l,int r){//查询[l,r]中的最大值
        int res=0;
        for (int i=31; i>=0; i--){
            if(pos[r][i]<l) 
                continue;
            if ((res^d[r][i])>res) 
                res^=d[r][i];
        }
        return res;
    }
    int queryMin(int l,int r) {//查询[l,r]中的最小值
        for(int i=0; i<=60; i++){
            if(pos[r][i]<l)
                continue;
            if(d[r][i])
                return d[r][i];
        }
        return 0;
    }
}PLB;