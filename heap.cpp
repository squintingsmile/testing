#include <iostream>
#include <vector>
#include <array>

class max_heap{
public:
    int size = 0;
    std::vector<int> vec;

    int inline parent(int i){
        return i / 2;
    }

    int inline left(int i){
        return 2 * i;
    }

    int inline right(int i){
        return 2 * i + 1;
    }

    void exchange(int &i, int &j){
        int tmp = i;
        i = j;
        j = tmp;
    }


    void max_heapify(int i) {
        int largest = i;
        while (i < size) {
            int l = left(i);
            int r = right(i);
            if (l < size && vec[l] > vec[i])
                largest = l;
            if (r < size && vec[r] > vec[largest])
                largest = r;
            if (largest != i) {
                exchange(vec[largest], vec[i]);
                i = largest;
            } else {
                break;
            }
        }
    }

   void build_max_heap(std::vector<int> arr){
       vec = arr;
       vec.insert(vec.begin(),0);
       size = arr.size() + 1;
       for (int i = 1; i < arr.size(); ++i){
           vec[i] = arr[i-1];
       }
       for (int i = arr.size() / 2 ; i > 0; --i) {
           max_heapify(i);
       }
   }
    void print_vec(){
        for (int i : vec){
            std::cout << i;
        }
        std::cout << std::endl;
    }

    void heap_sort(){
        for (int i = vec.size() - 1; i > 1; --i){
            std::cout << vec[1] << std::endl;
            exchange(vec[i], vec[1]);
            size -= 1;
            max_heapify(1);
        }
        std::cout << vec[1] << std::endl;
    }
};

int main(){
    std::vector<int> arr{1,2,3,5,7,8,9,4,6};
    max_heap heap = max_heap();
    heap.build_max_heap(arr);
    heap.heap_sort();
    return 0;
}