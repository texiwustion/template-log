#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7;
vector<int> pri;
int minp[N];

void pre(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!minp[i])
        {
            pri.push_back(i);
            minp[i] = i;
        }
        for (int pri_j : pri)
        {
            if (i * pri_j > n)
                break;
            if (!minp[i * pri_j])
                minp[i * pri_j] = pri_j;
            if (i % pri_j == 0)
            {
                break;
            }
        }
    }
}