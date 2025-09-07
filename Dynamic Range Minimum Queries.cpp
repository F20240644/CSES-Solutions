#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

struct SegmentTree
{
    std::vector<long long> Tree;
    int N;
    SegmentTree(std::vector<int> &v)
    {
        int n = v.size();
        N = 1 << (int)ceil(log2(n));
        for (int i = n; i < N; i++)
            v.emplace_back(INT_MAX);
        Tree.resize(2 * N, INT_MAX);
        for (int i = 0; i < N; i++)
        {
            Tree[N + i] = v[i];
        }
        for (int i = N - 1; i >= 1; i--)
        {
            Tree[i] = std::min(Tree[2 * i], Tree[2 * i + 1]);
        }
    }
    long long minm(int query_lo, int query_hi)
    {
        return query(1, 0, N - 1, query_lo, query_hi);
    }
    long long query(int node, int node_lo, int node_hi, int query_lo, int query_hi)
    {
        if (query_lo <= node_lo && node_hi <= query_hi)
            return Tree[node];
        if (node_hi < query_lo || query_hi < node_lo)
            return LLONG_MAX;
        int last_in_left = (node_lo + node_hi) / 2;
        return std::min(query(2 * node, node_lo, last_in_left, query_lo, query_hi), query(2 * node + 1, last_in_left + 1, node_hi, query_lo, query_hi));
    }

    void update(int pos, int val)
    {
        Tree[N + pos] = val;
        for (int j = (N + pos) / 2; j >= 1; j /= 2)
        {
            Tree[j] = std::min(Tree[2 * j], Tree[2 * j + 1]);
        }
    }
};

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    SegmentTree T(v);
    while (q--)
    {
        int m, l, r;
        std::cin >> m >> l >> r;
        if (m == 1)
        {
            T.update(l - 1, r);
        }
        else
        {
            std::cout << T.minm(l - 1, r - 1) << "\n";
        }
    }
    return 0;
}