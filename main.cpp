#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <list>
#include <deque>
#include <random>

class ptr{
public:
    int i;
    explicit ptr(int t) : i(t) {}
    ptr(){i = 0;}

};

int main() {
    ptr p_1 = ptr(10);
    ptr p_2 = ptr(5);
    ptr *q_1 = &p_1;
    ptr *q_2 = &p_2;
    ptr *q_3 = nullptr;
    q_3 = q_1;
    q_1 = q_2;
    q_2 = q_3;
    std::cout << (*p_1).i << std::endl;
}



