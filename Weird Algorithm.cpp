#include <bits/stdc++.h>

int main(){
    long long n;
    std::cin>>n;
    while(n!=1){
        std::cout<<n<<" ";
        if(n%2){
            std::cout<<3*n+1<<" ";
            n=(3*n+1)/2;
        }
        else n/=2;
    }
    std::cout<<n<<"\n";
}