#include <iostream>
#include <set>

void foo(std::string& s, int i, std::set<std::string>& st) {
    int n = s.size();
    for (int j = i; j < n; j++) {
        std::swap(s[i], s[j]);
        st.insert(s);
        foo(s, i + 1, st);
        std::swap(s[i], s[j]);
    }
}

int main(){
    std::string s;
    std::cin >> s;
    std::set<std::string> ans;
    foo(s, 0, ans);
    std::cout << ans.size() << "\n";
    for (auto str : ans) {
        std::cout << str << "\n";
    }
    return 0;
}