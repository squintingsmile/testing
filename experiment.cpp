#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec{1,2,3,4,5,6};
    for (int i : vec){
        std::cout << i << std::endl;
    }
}