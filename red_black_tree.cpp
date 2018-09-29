#include <iostream>

template <typename T, typename U>
class red_black_tree{
    typedef T key_type;
    typedef U val_type;
    const bool red = true;
    const bool black = false;
    int size;

    class node{
    public:
        key_type key;
        val_type val;
        node *left;
        node *right;
        bool color;

        node(key_type key, val_type val, bool color) :
                key(key),
                val(val),
                left(nullptr),
                right(nullptr),
                color(color) {}
    };

    bool is_red(node *nd){
        if (nd == nullptr)
            return false;
        return nd->color == red;
    }

    node *rotate_left(node *nd){
        node *x = nd->right;
        nd->right = x->left;
        x->left = nd;
        x->color = nd->color;
        nd->color = red;
        return x;
    }

    node *rotate_right(node *nd){
        node *x = nd->left;
        nd->left = x->right;
        x->right = nd;
        x->color = nd->color;
        nd->color = red;
        return x;
    }

    node *insert_single_two_node(node *nd){
        if (size == 1){
            if (nd->key < root->key) {
                root->left = nd;
                nd->color = red;
                return nd;
            }
            if (nd->key > root->key){
                root->right = nd;
                root = rotate_left(root);
                return root;
            }
        }
        return nullptr;
    }

    node *insert_bottom_two_node(node *nd){
        
    }

public:
    node *root = nullptr;
    explicit red_black_tree(node *nd) : root(nd), size(1) {}

    node *insert(){

    }

};