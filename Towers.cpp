#include <iostream>
#include <vector>
#include <set>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    std::multiset<int> tower;
    int cnt = 0;
    for (int x : v)
    {
        if (tower.empty())
        {
            tower.insert(x);
            cnt++;
        }
        else
        {
            auto it = tower.upper_bound(x);
            if (it == tower.end())
            {
                cnt++;
                tower.insert(x);
            }
            else
            {
                tower.erase(it);
                tower.insert(x);
            }
        }
    }
    std::cout << cnt << "\n";
    return 0;
}