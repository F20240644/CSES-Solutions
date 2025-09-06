#include <iostream>
#include <algorithm>
#include <climits>

int main()
{
    int n;
    std::cin >> n;
    long long arr[n], ps[n + 1];
    ps[0] = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + arr[i];
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        __int128 curr = ((__int128)(2 * i - n) * x + (__int128)ps[n] - 2 * (__int128)ps[i]);
        ans = std::min(ans, (long long)curr);
    }
    std::cout << ans << "\n";
    return 0;
}