#include <iostream>
#include <algorithm>

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Left-Left case
        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }
        // Right-Right case
        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }
        // Left-Right case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right-Left case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void printInorder() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avl;

    int n, key;
    std::cout << "Enter the number of elements to insert: ";
    std::cin >> n;

    std::cout << "Enter the elements to insert, one by one:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> key;
        avl.insert(key);
    }

    std::cout << "Inorder traversal of AVL tree: ";
    avl.printInorder();

    return 0;
}
