// AVL TREE IMPLEMENTATION

// based on a binary search tree (BST)
// complemented by implementing rotations for balancing

#include <vector>
#include <iostream>
using namespace std;

class Node {
    int key;
    int value;

public:

    Node (int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {};

    Node* left;
    Node* right;
    int get_key () { return this->key; };
    int get_val () { return this->value; };
    void set_key (int k) { this->key = k; };
    void set_val (int v) { this->value = v; };
    // void set_left (Node* left_node) { this->left = left_node; };
    // void set_right (Node* right_node) { this->right = right_node; };
};


class BST {
public:

    Node* root;
    int node_count;

    BST() : root(nullptr), node_count(0) {};
    ~BST() = default;
    int find (int k);
    void insert (int k, int v);
    int remove (int k);

private:

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

        if (rt->get_key() == k) return rt->get_val();
        if (rt->get_key() > k) return findhelp(rt->left, k);
        else return findhelp(rt->right, k);
    }

    Node* inserthelp (Node* rt, int k, int v) {
        
        if (rt == nullptr) {
            return new Node(k, v);
        }

        if (rt->get_key() > k) rt->left = inserthelp(rt->left, k, v);
        else rt->right = inserthelp(rt->right, k, v);

        return rt;
    }

    Node* removehelp (Node* rt, int k) {

        if (rt == nullptr) return nullptr;
        
        if (rt->get_key() > k)
            rt->left = removehelp(rt->left, k);
        
        else if (rt->get_key() < k)
            rt->right = removehelp(rt->right, k);

        else {
            Node* temp = getmin(rt->right);
            rt->set_val(temp->get_val());
            rt->set_key(temp->get_key());
            rt->right = deletemin(rt->right);
        }

        return rt;
    }
};

int BST::find (int k) {
    return findhelp(this->root, k);
};

void BST::insert (int k, int v) {
    this->root = inserthelp(this->root, k, v);
    this->node_count++;
};

int BST::remove (int k) {
    int temp = findhelp(this->root, k);
    if (temp != -1) {
        this->root = removehelp(this->root, k);
        this->node_count--;
    }
    return temp;
};


void traverse (Node* rt) {

    if (rt == nullptr) return;

    cout << rt->get_key() << " ";
    traverse(rt->left);
    traverse(rt->right);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST bst;
    bst.insert(37, 37);
    bst.insert(24, 24);
    bst.insert(42, 42);
    bst.insert(7, 0);
    bst.insert(2, 0);
    bst.insert(40, 0);
    bst.insert(42, 1);
    bst.insert(32, 0);
    bst.insert(120, 0);

    traverse(bst.root); cout << "\n";
    // expected: 37 24 7 2 32 42 40 42 120

    cout << bst.find(42) << "\n";
    // expected: 42

    bst.remove(37);
    traverse(bst.root); cout << "\n";
    // expected: 40 24 7 2 32 42 42 120

    return 0;
}