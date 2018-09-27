#include <iostream>
#include <string>
#include <vector>
#include <deque>
template <typename T, typename U>
class BST{
public:

    typedef T keytype;
    typedef U valtype;

    class d_que{
    private:
        struct nd{
            nd *next;
            nd *previous;
            keytype key;
            nd(keytype key) : key(key), previous(nullptr), next(nullptr) {}
            nd() = default;
            ~nd() = default;
        };

        nd *front = nullptr;
        nd *end = nullptr;

    public:
        int size = 0;
        void push_front(keytype key){
            auto n = new nd(key);
            if (size == 0){
                front = n;
                end = n;
                size += 1;
                return;
            }
            n->next = front;
            front = n;
            size += 1;
        }

        void push_back(keytype key){
            auto n = new nd(key);
            if (size == 0){
                front = n;
                end = n;
                size += 1;
                return;
            }
            n->previous = end;
            end = n;
            size += 1;
        }

        keytype pop_front(){
            if (size == 0)
                return NULL;
            if (size == 1){
                keytype tmp = front->key;
                delete front;
                front = nullptr;
                end = nullptr;
                size -= 1;
                return tmp;
            }
            keytype tmp = front->key;
            nd *tmp_ptr = front;
            front = tmp_ptr->next;
            delete tmp_ptr;
            size -= 1;
            return tmp;
        }

        keytype pop_back(){
            if (size == 0)
                return NULL;
            if (size == 1){
                keytype tmp = front->key;
                delete front;
                front = nullptr;
                end = nullptr;
                size -= 1;
                return tmp;
            }
            keytype tmp = end->key;
            nd *tmp_ptr = end;
            end = tmp_ptr->next;
            delete tmp_ptr;
            size -= 1;
            return tmp;
        }
    };

    class node{
    public:
        keytype key;
        valtype val;
        node *left = nullptr;
        node *right = nullptr;
        node() = default;
        node(keytype key, valtype val) : key(key), val(val) {}
    };

    size_t B_size = 0;

    node root;

    BST(keytype key, valtype val){
        root = node(key, val);
        B_size = 1;
    }

    int compare(keytype key1, keytype key2){
        int x = key1 >= key2 ? 1 : -1;
        return x;
    }

    int size(node* nd) {
        if (nd == nullptr)
            return 0;
        return size(nd->left) + size(nd->right) + 1;
    }

    void put(node *nd){
        node *current_node = &root;
        while (true) {
            int cmp = compare(nd->key, current_node->key);
            if (cmp == 1 && current_node->right != nullptr) {
                current_node = current_node->right;
                continue;
            }
            if (cmp == 1 && current_node->right == nullptr) {
                current_node->right = nd;
                B_size += 1;
                return;
            }
            if (cmp == -1 && current_node->left != nullptr){
                current_node = current_node->left;
                continue;
            }
            if (cmp == -1 && current_node->left == nullptr) {
                current_node->left = nd;
                B_size += 1;
                return;
            }
        }
    };

    valtype get(node x, keytype key){
        node *current_node = &x;
        while (true){
            if (current_node == nullptr){
                return NULL;
            }
            if (current_node->key == key) {
                return current_node->val;
            }
            if (current_node->key < key)
                current_node = current_node->right;
            if (current_node->key > key)
                current_node = current_node->left;
            }
        }

    node *select(node *nd, int rank) {
        node *current_node = nd;
        while (true){
            if (rank > size(current_node->left)) {
                current_node = current_node->right;
                rank -= size(current_node->left);
                continue;
            }

            if (rank == size(current_node->left))
                return current_node;

            if (rank < size(current_node->left)){
                current_node = current_node->left;
            }
        }
    }

    int rank(keytype key){
        node *current_node = &root;
        int rank = 0;
        while (true){
            if (key < current_node->key) {
                rank += 1;
                current_node = current_node->left;
            }
            if (key == current_node->key){
                rank += size(current_node->left);
                return rank;
            }
            if (key > current_node->key){
                rank += size(current_node->left) + 1;
                current_node = current_node->right;
            }
        }
    }

    node *delete_min(node *nd){
        if (nd->left == nullptr)
            return nd->right;
        nd->left = delete_min(nd->left);
        return nd;
    }

    node *min(node *nd){
        while (nd->left != nullptr){
            nd = nd->left;
        }
        return nd;
    }

    valtype delete_key(node *nd, keytype key) {
        if(nd == nullptr)
            return NULL;
        int cmp = compare(nd->key, key);
        if (cmp == 1) {
            nd->left = delete_key(nd->left, key);
        } else {
            if (cmp == -1) {
                nd->right = delete_key(nd->right, key);
            } else {
                if (nd->right == nullptr) return nd->left;
                if (nd->left == nullptr) return nd->right;
                node *t = nd;
                nd = min(t->right);
                nd->right = delete_min(nd->right);
                nd->left = t->left;
            }
        }
        return nd;
    }

    d_que* keys(keytype high, keytype low){
        auto q_ptr = new d_que();
        keys(high, low, &root, q_ptr);
        return q_ptr;
    }

    void keys(keytype high, keytype low, node *current_node, d_que* k_queue){
        if (current_node == nullptr)
            return;
        if (current_node->key <= high && current_node-> key >= low) {
            k_queue->push_front(current_node->key);
        }
        if (current_node->key < high)
            keys(high, low, current_node->right, k_queue);
        if (current_node->key > low)
            keys(high, low, current_node->left, k_queue);
    }

};

typedef BST<int, int> bin_i;

int main(){
    bin_i bin(-1, 2);
    for (int t = 0; t < 10; t++){
        bin.put(new bin_i::node(2 * t, t + 1));
    }
    for (int t = 0; t < 10; t++){
        bin.put(new bin_i::node(2 * t + 1, t + 1));
    }
    auto ptr = bin.keys(10, 2);
    for (int i = 0; i < ptr->size; i++)
        std::cout << ptr->pop_front() << std::endl;
}