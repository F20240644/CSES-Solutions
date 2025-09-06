#include <iostream>
#include <vector>

const int INF = 1e9;

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coin(n);
    for (int i = 0; i < n; i++)
        std::cin >> coin[i];
    std::vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j : coin)
        {
            if (i - j >= 0)
            {
                dp[i] = std::min(dp[i], dp[i - j] + 1);
            }
        }
    }
    if (dp[x] == INF)
        std::cout << -1 << "\n";
    else
        std::cout << dp[x] << "\n";
    return 0;
}