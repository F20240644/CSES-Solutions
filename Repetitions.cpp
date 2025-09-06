#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    int ans = 0;
    int i = 0;
    int n = (int)s.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && s[j] == s[i])
            j++;
        ans = std::max(ans, j - i);
        i = j;
    }
    std::cout << ans << "\n";
    return 0;
}