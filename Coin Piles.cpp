#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int a, b;
        std::cin >> a >> b;
        if ((2 * a - b) % 3)
        {
            std::cout << "NO\n";
            continue;
        }
        if ((2 * b - a) % 3)
        {
            std::cout << "NO\n";
            continue;
        }
        int x = (2 * a - b) / 3;
        int y = (2 * b - a) / 3;
        if (x < 0 || y < 0)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
    return 0;
}