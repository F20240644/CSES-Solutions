#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](auto p1, auto p2)
         {
        if(p1.second!=p2.second) return p1.second<p2.second;
        return p1.first<p2.first; });
    int ans = 0;
    std::pair<int, int> curr = {0, 0};
    for (auto p : v)
    {
        if (curr == std::pair<int, int>(0, 0) || curr.second <= p.first)
        {
            ans++;
            curr = p;
        }
    }
    std::cout << ans << "\n";
    return 0;
}