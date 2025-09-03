#include <iostream>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;
    std::string a = "", ans = "";
    int arr[26] = {0};
    for (char ch : s) {
        arr[ch - 'A']++;
    }
    char oddChar = 'a';
    int oddcnt = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 == 1) {
            oddcnt++;
            oddChar = 'A' + i;
            arr[i]--;
        }
        if (oddcnt >= 2) {
            std::cout << "NO SOLUTION\n";
            return 0;
        }
        a += std::string(arr[i] / 2, 'A' + i);
    }
    ans = a;
    reverse(a.begin(),a.end());
    if (oddcnt > 0) {
        ans += oddChar;
        ans += a;
    } else {
        ans += a;
    }
    std::cout << ans << "\n";
    return 0;
}