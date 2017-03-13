//in the name of God

#include <iostream>
using namespace std;

struct Node {
        int key;
        Node *right, *left;
};

Node* search(Node *root, int key) {
        if (!root || root->key == key)
                return root;
        if (root->key < key)
                return search(root->right, key);
        return search(root->left, key);
}

Node* createNode(int item) {
        Node *nd = (Node *)malloc(sizeof(Node));
        nd->key = item;
        nd->left = nd->right = NULL;
        return nd;
}

void inorder(Node *root) {
        if (root) {
                inorder(root->left);
                printf("%d \n", root->key);
                inorder(root->right);
        }
}

Node* insert(Node *nd, int key) {
        if (!nd)
                return createNode(key);
        if (key < nd->key)
                nd->left = insert(nd->left, key);
        else if (key > nd->key)
                nd->right = insert(nd->right, key);
        return nd;
}

int main() {
        Node *root = NULL;
        root = insert(root, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);

        inorder(root);

        return 0;
}
