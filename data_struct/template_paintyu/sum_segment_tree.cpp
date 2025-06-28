// 加和线段树，支持区间加、区间和、区间平方和
using ll = long long;

template <typename T>
struct node
{
    T sum = 0, sqsum = 0;
    int l, r;
    T add = 0;
    node() {}
    node(int l0, int r0) : l(l0), r(r0) {}
};

template <typename T>
struct segment_tree
{   
    int n;
    vector<T> a;
    vector< node<T> > w;

    void push_up(int u)
    {   
        w[u].sum = w[u << 1].sum + w[u << 1 | 1].sum;
        w[u].sqsum = w[u << 1].sqsum + w[u << 1 | 1].sqsum;
    }

    void build(int u, int l, int r)
    {
        w[u].l = l, w[u].r = r;
        if(l == r)
        {
            w[u].sum = a[l];
            w[u].sqsum = a[l] * a[l];
            return;
        }
        else
        {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            push_up(u);
        }
    }

    segment_tree(vector<T> a0) : a(a0)
    {
        n = a.size() - 1;
        w.resize(4 * n + 1);
        build(1, 1, n);
        return;
    }

    void push_down(int u)
    {
        node<T> &root = w[u], &lson = w[u << 1], &rson = w[u << 1 | 1];
        if(root.add)
        {
            lson.sqsum += (T)(lson.r - lson.l + 1) * root.add * root.add;
            lson.sqsum += 2 * lson.sum * root.add;
            rson.sqsum += (T)(rson.r - rson.l + 1) * root.add * root.add;
            rson.sqsum += 2 * rson.sum * root.add;
            lson.sum += (T)(lson.r - lson.l + 1) * root.add;
            rson.sum += (T)(rson.r - rson.l + 1) * root.add;
            lson.add += root.add;
            rson.add += root.add;
            root.add = 0;
        }
    }

    void add(int u, int l, int r, T x)
    {
        if(w[u].l >= l && w[u].r <= r)
        {
            w[u].sqsum += (T)(w[u].r - w[u].l + 1) * x * x;
            w[u].sqsum += 2 * w[u].sum * x;
            w[u].sum += (T)(w[u].r - w[u].l + 1) * x;
            w[u].add += x; // 记得加懒标记！
        }
        else
        {
            push_down(u);
            int mid = (w[u].l + w[u].r) >> 1;
            if(l <= mid) add(u << 1, l, r, x);
            if(r >= mid + 1) add(u << 1 | 1, l, r, x);
            push_up(u);
        }
    }

    node<T> query(int u, int l, int r)
    {
        node<T> res(l, r);
        if(w[u].l >= l && w[u].r <= r)
        {
            res.sum = w[u].sum;
            res.sqsum = w[u].sqsum;
            return res;
        }
        else
        {
            push_down(u); // query时也要push_down！！！
            int mid = (w[u].l + w[u].r) >> 1;
            if(l <= mid)
            {
                node<T> lres = query(u << 1, l, r);
                res.sum += lres.sum;
                res.sqsum += lres.sqsum;
            }
            if(r >= mid + 1)
            {
                node<T> rres = query(u << 1 | 1, l, r);
                res.sum += rres.sum;
                res.sqsum += rres.sqsum;
            }
            return res;
        }
    }
};