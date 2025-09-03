#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int ans=0;
    while(n>0){
        ans+=(n/5);
        n/=5;
    }
    std::cout<<ans<<"\n";
    return 0;
}