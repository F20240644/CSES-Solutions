#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::multiset<int> h;
    int t[m] = {0};
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        h.insert(temp);
    }
    for (int i = 0; i < m; i++)
        std::cin >> t[i];
    for (int x : t)
    {
        auto it = h.lower_bound(x);
        if (*it == x)
        {
            std::cout << x << "\n";
            h.erase(it);
        }
        else
        {
            if (it == h.begin())
            {
                std::cout << -1 << "\n";
            }
            else
            {
                it--;
                std::cout << *it << "\n";
                h.erase(it);
            }
        }
    }
    return 0;
}