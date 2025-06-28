// ST表，支持O(1)查询区间最大值、区间最小值
template <typename T>
struct sparse_table
{
	vector<int> log_2;
	vector< vector<T> > amax, amin;
	sparse_table(vector<T> a)
	{
		int n = a.size() - 1;
		log_2.resize(n + 5);
		for(int i = 2; i <= n + 5; i ++)
			log_2[i] = log_2[i >> 1] + 1;
		
		int h = log_2[n] + 5;
		amax.resize(n + 5), amin.resize(n + 5);
		for(int i = 0; i <= n; i ++) 
			amax[i].resize(h), amin[i].resize(h);

		for(int i = 1; i <= n; i ++)
			amax[i][0] = amin[i][0] = a[i];

		for(int j = 1; (1 << j) <= n; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				amax[i][j] = max(amax[i][j - 1], amax[i + (1 << (j - 1))][j - 1]);
				amin[i][j] = min(amin[i][j - 1], amin[i + (1 << (j - 1))][j - 1]);
			}
	}

	T query_max(int l, int r)
	{
		int d = log_2[r - l + 1];
		return max(amax[l][d], amax[r - (1 << d) + 1][d]);
	}

	T query_min(int l, int r)
	{
		int d = log_2[r - l + 1];
		return min(amin[l][d], amin[r - (1 << d) + 1][d]);
	}
};
