#include <iostream>
#include <vector>

struct PrefixSum
{
    std::vector<long long> ps;
    PrefixSum(const std::vector<int> &v)
    {
        int n = v.size();
        ps.resize(n + 1, 0LL);
        for (int i = 0; i < n; i++)
        {
            ps[i + 1] = ps[i] + v[i];
        }
    }
    long long sum(int l, int r)
    {
        return ps[r + 1] - ps[l];
    }
};

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    PrefixSum p(v);
    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << p.sum(a - 1, b - 1) << "\n";
    }
    return 0;
}