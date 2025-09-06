#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
    long long n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        std::cin >> l >> r;
        v.emplace_back(l, 1);
        v.emplace_back(r + 1, -1);
    }
    sort(v.begin(), v.end());
    long long curr = 0, ans = LLONG_MIN;
    for (auto p : v)
    {
        curr += p.second;
        ans = std::max(ans, curr);
    }
    std::cout << ans << "\n";
    return 0;
}