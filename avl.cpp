// AVL TREE IMPLEMENTATION

// based on a binary search tree (BST)
// complemented by implementing rotations for balancing

#include <vector>
#include <iostream>
using namespace std;

class Node {
public:

    int key;
    int value;
    int height;
    Node* left;
    Node* right;

    Node (int k, int v) : key(k), value(v), height(-1), left(nullptr), right(nullptr) {};
};


class AVL {
public:

    Node* root;
    int node_count;

    AVL() : root(nullptr), node_count(0) {};
    ~AVL() = default;
    int find (int k);
    void insert (int k, int v);
    int remove (int k);

private:

    // auxiliary for avl

    int h (Node* rt) {
        if (rt == nullptr) return -1;
        return rt->height;
    }

    int get_balance (Node* rt) {
        if (rt == nullptr) return 0;
        return h(rt->left) - h(rt->right);
    }

    Node* l_rotate (Node* rt) {

        Node* l = rt->left;
        Node* lr = l->right;

        l->right = rt;
        rt->left = lr;
        rt->height = 1 + max(h(rt->left), h(rt->right));
        l->height = 1 + max(h(l->left), h(l->right));
        
        return l;
    }

    Node* r_rotate (Node* rt) {

        Node* r = rt->left;
        Node* rl = r->right;

        r->right = rt;
        rt->left = rl;
        rt->height = 1 + max(h(rt->left), h(rt->right));
        r->height = 1 + max(h(r->left), h(r->right));
        
        return r;
    }

    // auxiliary functions

    Node* getmin (Node* rt) {
        if (rt->left == nullptr) return rt;
        return getmin(rt->left);
    }

    Node* deletemin (Node* rt) {
        if (rt->left == nullptr) return rt->right;
        rt->left = deletemin(rt->left);
        return rt;
    }

    // using -1 as = node not found
    int findhelp (Node* rt, int k) {

        if (rt == nullptr) return -1;

        if (rt->key == k) return rt->value;
        if (rt->key > k) return findhelp(rt->left, k);
        else return findhelp(rt->right, k);
    }

    Node* inserthelp (Node* rt, int k, int v) {
        
        if (rt == nullptr) {
            return new Node(k, v);
        }

        if (rt->key > k) rt->left = inserthelp(rt->left, k, v);
        else rt->right = inserthelp(rt->right, k, v);


        // complementary operations for avl (rotations)

        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance_factor = get_balance(rt);

        if (balance_factor < -1 && k >= rt->right->key) return l_rotate(rt);
        if (balance_factor > 1 && k < rt->left->key) return r_rotate(rt);

        if (balance_factor > 1 && k >= rt->left->key) {
            rt->left = l_rotate(rt->left);
            return r_rotate(rt);
        }

        if (balance_factor < -1 && k < rt->right->key) {
            rt->right = r_rotate(rt->right);
            return l_rotate(rt);
        }

        return rt;
    }

    Node* removehelp (Node* rt, int k) {

        if (rt == nullptr) return nullptr;
        
        if (rt->key > k)
            rt->left = removehelp(rt->left, k);
        
        else if (rt->key < k)
            rt->right = removehelp(rt->right, k);

        else {
            Node* temp = getmin(rt->right);
            rt->value = temp->value;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }

        return rt;
    }
};

int AVL::find (int k) {
    return findhelp(this->root, k);
};

void AVL::insert (int k, int v) {
    this->root = inserthelp(this->root, k, v);
    this->node_count++;
};

int AVL::remove (int k) {
    int temp = findhelp(this->root, k);
    if (temp != -1) {
        this->root = removehelp(this->root, k);
        this->node_count--;
    }
    return temp;
};


void traverse (Node* rt) {

    if (rt == nullptr) return;

    cout << rt->key << " ";
    traverse(rt->left);
    traverse(rt->right);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AVL avl;
    avl.insert(4, 0);
    avl.insert(6, 0);
    avl.insert(8, 2);
    avl.insert(3, 0);
    avl.insert(2, 0);
    avl.insert(5, 0);


    traverse(avl.root); cout << "\n";
    // expected: 4 3 2 6 5 8

    cout << avl.find(8) << "\n";
    // expected: 2

    avl.remove(6);
    traverse(avl.root); cout << "\n";
    // expected: 4 3 2 5 8

    return 0;
}