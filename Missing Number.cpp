#include <iostream>

int main()
{
    long long n, temp, sum = 0;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> temp;
        sum += temp;
    }
    std::cout << ((n * n + n) / 2) - sum << "\n";
    return 0;
}