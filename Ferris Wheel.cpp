#include <iostream>
#include <algorithm>

int main()
{
    int n, x;
    std::cin >> n >> x;
    int p[n] = {0};
    for (int i = 0; i < n; i++)
        std::cin >> p[i];
    std::sort(p, p + n);
    int l = 0, r = n - 1;
    int ans = 0;
    while (r > l)
    {
        if (p[l] + p[r] <= x)
        {
            l++;
        }
        r--;
        ans++;
    }
    if (l == r)
        ans++;
    std::cout << ans << "\n";
}