#include <iostream>
#include <vector>

struct SparseTable
{
    int n, LOG;
    std::vector<std::vector<int>> table;
    SparseTable(const std::vector<int> &v)
    {
        n = v.size();
        LOG = 32 - __builtin_clz(n);
        table.assign(n, std::vector<int>(LOG));
        for (int i = 0; i < n; i++)
        {
            table[i][0] = v[i];
        }
        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                table[i][j] = std::min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int L, int R)
    {
        int j = 31 - __builtin_clz(R - L + 1);
        return std::min(table[L][j], table[R - (1 << j) + 1][j]);
    }
};

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    SparseTable T(v);
    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        std::cout << T.query(a, b) << "\n";
    }
    return 0;
}