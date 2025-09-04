#include <iostream>
#include <set>

int main(){
    int n;
    std::cin>>n;
    std::set<int>st;
    for(int i=0;i<n;i++){
        int temp;
        std::cin>>temp;
        st.insert(temp);
    }
    std::cout<<st.size()<<"\n";
}