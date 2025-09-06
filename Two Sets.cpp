#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    long long a = 0, b = 0;
    std::vector<int> A, B;
    for (int i = n; i > 0; i--)
    {
        if (b < a)
        {
            B.emplace_back(i);
            b += i;
        }
        else
        {
            A.emplace_back(i);
            a += i;
        }
    }
    if (a != b)
    {
        std::cout << "NO\n";
    }
    else
    {
        std::cout << "YES\n";
        std::cout << A.size() << "\n";
        for (int x : A)
            std::cout << x << " ";
        std::cout << "\n";
        std::cout << B.size() << "\n";
        for (int x : B)
            std::cout << x << " ";
        std::cout << "\n";
    }
}