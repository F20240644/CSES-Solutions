#include <iostream>
#include <map>

int main(){
    int n,x;
    std::cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) std::cin>>arr[i];
    std::map<int,int>mp;
    bool ok=false;
    for(int i=0;i<n;i++){
        if(mp[x-arr[i]]==0){
            mp[arr[i]]=i+1;
        }else{
            std::cout<<mp[x-arr[i]]<<" "<<i+1<<"\n";
            ok=true;
            break;
        }
    }
    if(!ok) std::cout<<"IMPOSSIBLE\n";
    return 0;
}