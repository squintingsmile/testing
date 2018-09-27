#include <iostream>
#include <string>
#include <vector>
template  <typename T, typename U> class node{
public:
    T key;
    U val;
    node *next;
    node() = default;
    node(T key, U val) : key(key), val(val), next(nullptr) {}
    ~node() = default;
};

template <typename T, typename U> class sequential_symbol_table{
public:
    typedef T key_type;
    typedef U val_type;

    node<key_type, val_type> first;

    size_t sz = 0;

    sequential_symbol_table() = default;

    sequential_symbol_table(key_type key, val_type val){
        first.key = key;
        first.val = val;
        sz = 1;
    }

    node* add_node(key_type key, val_type val, node &this_node){
        if (sz == 0){
            first.key = key;
            first.val = val;
            sz += 1;
            return &first;
        }
        node *next_node = new node(key, val);
        if (this_node.next == nullptr) {
            this_node.next = next_node;
        } else {
            (*next_node).next = this_node.next;
            this_node.next = next_node;
        }
        sz += 1;
        return next_node;
    }

    std::pair<key_type, val_type> delete_node(node before){
        std::pair<key_type, val_type> p = {(*before.next).key, (*before.next).val};
        before.next = (*before.next).next;
        return p;
    };

    val_type delete_node(key_type key){
        for (node x = first; x.next != nullptr; x = *x.next ) {
            if (key == x.key) {
                val_type tmp = x.val;
                x.~x();
                return tmp;
            }
        }
        return NULL;
    }

    val_type get(key_type key){
        for (node x = first; x.next != nullptr; x = *x.next ){
            if (key == x.key)
                return x.val;
        }
        return NULL;
    }

    void put(key_type key, val_type val){
        for (node x = first; x.next != nullptr; x = *x.next ){
            if (key == x.key) {
                return;
            }
        }
        add_node(key, val, first);
    }
};

int main(){
    std::string s ("A+");
    std::string s0 ("A-");
    std::vector vec {"A+","A","A-","B+","B","B-",""};
    sequential_symbol_table<std::string, double> table = sequential_symbol_table(s, 4.3);
    table.put(s0, 3.7);

}

