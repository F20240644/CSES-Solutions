#include <iostream>
#include <climits>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    long long currSum = 0, maxSum = LLONG_MIN;
    for (int x : arr)
    {
        currSum += x;
        maxSum = std::max(currSum, maxSum);
        if (currSum < 0)
            currSum = 0;
    }
    std::cout << maxSum << "\n";
    return 0;
}