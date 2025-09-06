#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        long long row, col;
        std::cin >> row >> col;
        long long ans = 0;
        if (row > col)
        {
            if (row % 2 == 1)
            {
                ans = (row - 1) * (row - 1);
                ans += col;
            }
            else
            {
                ans = (row * row) - col + 1;
            }
        }
        else
        {
            if (col % 2 == 1)
            {
                ans = (col * col) - row + 1;
            }
            else
            {
                ans = (col - 1) * (col - 1);
                ans += row;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}