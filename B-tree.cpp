// Write a program to implement a B-Tree.
#include <iostream>
using namespace std;

class BTreeNode {
public:
    int *keys;
    int t;                // Minimum degree
    BTreeNode **child;
    int n;
    bool leaf;

    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;
        keys = new int[2 * t - 1];
        child = new BTreeNode *[2 * t];
        n = 0;
    }

    void traverse() {
        for (int i = 0; i < n; i++) {
            if (!leaf) child[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!leaf) child[n]->traverse();
    }

    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int t) {
        this->t = t;
        root = nullptr;
    }

    void traverse() {
        if (root) root->traverse();
    }

    void insert(int k);
};

void BTree::insert(int k) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->child[0] = root;
            s->splitChild(0, root);

            int i = (s->keys[0] < k) ? 1 : 0;
            s->child[i]->insertNonFull(k);

            root = s;
        } else root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    } else {
        while (i >= 0 && keys[i] > k) i--;
        if (child[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, child[i + 1]);
            if (keys[i + 1] < k) i++;
        }
        child[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
    if (!y->leaf)
        for (int j = 0; j < t; j++) z->child[j] = y->child[j + t];

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--) child[j + 1] = child[j];
    child[i + 1] = z;

    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n++;
}

int main() {
    BTree tree(3); // B-tree of order 3

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "B-Tree Traversal: ";
    tree.traverse();
}
