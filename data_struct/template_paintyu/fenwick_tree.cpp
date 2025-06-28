// 树状数组，支持单点加、单点修改、前缀和、区间和
template <typename T>
struct fenwick_tree
{
	int n;
	vector<T> a, w;
	
	fenwick_tree(int n0)
	{
		n = n0;
		a.assign(n + 1, 0);
		w.assign(n + 1, 0);
		return;
	}
	
	void add(int p, T x)
	{
		for(; p <= n; p += p & (-p)) w[p] += x;
		return;
	}
	
	fenwick_tree(vector<T> a0) 
	{
		int n = a0.size() - 1; a = a0; 
		w.assign(n + 1, 0);
		for(int i = 1; i <= n; i ++) add(i, a[i]);
		return;
	}
	
	void modify(int p, T x) 
	{
		T d = x - a[p];
		add(p, d);
		return;
	}
	
	T psum(int p)
	{
		T res = 0;
		for(; p >= 1; p -= p & (-p)) res += w[p];
		return res;
	}
	
	T sum(int l, int r)
	{
		if(l > r) return 0;
		return psum(r) - psum(l - 1);
	}
};