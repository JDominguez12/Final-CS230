#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {
        srand(time(nullptr)); 
    }

    ~BinaryTree() {
        clear(root);
    }

    void insertRandom(int minValue, int maxValue) {
        int randomValue = minValue + rand() % (maxValue - minValue + 1);
        root = insert(root, randomValue);
    }

    void printInOrder() const {
        printInOrder(root);
        cout << endl;
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void printInOrder(TreeNode* node) const {
        if (!node) return;
        printInOrder(node->left);
        cout << node->value << " ";
        printInOrder(node->right);
    }

    void clear(TreeNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};

#endif 