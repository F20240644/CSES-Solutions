#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, n;
    std::cin >> x >> n;
    std::set<int> active;
    std::multiset<int> length;
    active.insert(0);
    active.insert(x);
    length.insert(x);
    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        auto left = active.upper_bound(a);
        auto right = left--;
        int prevLength = *right - *left;
        length.erase(length.find(prevLength));
        active.insert(a);
        length.insert(a - *left);
        length.insert(*right - a);
        ans.emplace_back(*(length.rbegin()));
    }
    for (int x : ans)
        std::cout << x << " ";
    std::cout << "\n";
    return 0;
}