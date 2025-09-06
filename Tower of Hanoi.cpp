#include <iostream>

void foo(int n, int st, int help, int end)
{
    if (n == 1)
    {
        std::cout << st << " " << end << "\n";
        return;
    }
    foo(n - 1, st, end, help);
    std::cout << st << " " << end << "\n";
    foo(n - 1, help, st, end);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << (1 << n) - 1 << "\n";
    foo(n, 1, 2, 3);
}