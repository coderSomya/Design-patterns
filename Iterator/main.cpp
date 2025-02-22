#include <vector>
#include <iostream>

int main(){
    std::vector<int> nums {1,2,3,4,5,6,7};
    
    auto it = nums.begin();
    while(it!=nums.end()){
        int item = *std::next(it,0);
        std::cout<<item<<" ";
        std::advance(it,1);
        //this traversal can be modified
        //according to our needs
    }
    
    std::cout<<"\n";
}