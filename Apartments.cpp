#include <iostream>
#include <algorithm>

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    int need[n], av[m];
    for (int i = 0; i < n; i++)
        std::cin >> need[i];
    for (int i = 0; i < m; i++)
        std::cin >> av[i];
    std::sort(need, need + n);
    std::sort(av, av + m);
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (need[i] - k <= av[j] && av[j] <= need[i] + k)
        {
            ans++;
            i++;
            j++;
        }
        else if (av[j] < need[i] - k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    std::cout << ans << "\n";
    return 0;
}