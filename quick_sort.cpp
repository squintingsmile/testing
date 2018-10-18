#include <iostream>
#include <vector>

void exchange(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void quick_sort(std::vector<int> &vec, int start, int end){
    if (start == end || start == end + 1)
        return;
    int tmp = vec[start];
    int pos = start;
    for (int i = start + 1; i < end + 1; ++i){
        if(tmp > vec[i]){
            pos += 1;
            exchange(vec[pos], vec[i]);
        }
    }
    exchange(vec[start], vec[pos]);
    quick_sort(vec, start, pos-1);
    quick_sort(vec, pos+1, end);
}

int main(){
    std::vector<int> vec {9,8,7,6,5,4,2,1};
    quick_sort(vec,0,int(vec.size() - 1));
    for (int i : vec){
        std::cout << i << std::endl;
    }
}