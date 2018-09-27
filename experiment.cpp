#include <iostream>

int *c(int *ptr){
    ptr = new int(5);
    std::cout << *ptr << std::endl;
    return ptr;
}
int main(){
    int m = 10;
    int *t = &m;
    c(t);
    std::cout << *t << std::endl;
}