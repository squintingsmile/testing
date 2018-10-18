#include <iostream>

template <typename T, typename U>
class red_black_tree{
private:
    typedef T key_type;
    typedef U val_type;
    const bool red = true;
    const bool black = false;
    int size = 0;

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

    void flip_colors(node* nd){
        nd->right->color = black;
        nd->left->color = black;
        nd->color = red;
    }

public:

    node *root = nullptr;
    explicit red_black_tree(node *nd) : root(nd), size(1) {}

    red_black_tree(key_type key, val_type val) : size(1) {}

    void insert(key_type key, val_type val){
        root = insert(root, key, val);
        root->color = black;
    }

    node *insert(node *nd, key_type key, val_type val){
        if (nd == nullptr)
            return new node(key, val, red);

        if (key < nd->key)
            nd->left = insert(nd->left, key, val);
        if (key > nd->key)
            nd->right = insert(nd->right, key, val);
        if (key == nd->key)
            nd->val = val;

        if (is_red(nd->right) && !is_red(nd->left))
            nd = rotate_left(nd);
        if (is_red(nd->left) && is_red(nd->left->left))
            nd = rotate_right(nd);
        if (is_red(nd->left) && is_red(nd->right))
            flip_colors(nd);

        return nd;
    }

};

int main(){
    red_black_tree<int, int>::node *nd = new red_black_tree<int, int>::node(1, 1, false);
    red_black_tree<int, int> rbt;
    rbt.root = nd;
    rbt.insert(2, 2);

}