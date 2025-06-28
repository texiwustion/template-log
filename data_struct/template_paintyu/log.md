# 使用记录
## 洛谷P1471 方差
https://www.luogu.com.cn/problem/P1471

代码复用了sum_segment_tree模板内容，实现区间平均数和方差的计算
```cpp
int main()
{
    int n, m;
    cin >> n >> m;
    vector<double> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    segment_tree<double> tr(a);

    for(int i = 1; i <= m; i ++)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r;
            double x; // 千万别忘了数据类型！！！
            cin >> l >> r >> x;
            tr.add(1, l, r, x);
        }
        else if(op == 2 || op == 3)
        {
            int l, r;
            cin >> l >> r;
            node<double> ans = tr.query(1, l, r);
            double avr = ans.sum / (double)(r - l + 1);
            if(op == 2) cout << fixed << setprecision(4) << avr << "\n";
            else cout << fixed << setprecision(4) << ans.sqsum / double(r - l + 1) - avr * avr << "\n";
        }
    }
    return 0;
}
```