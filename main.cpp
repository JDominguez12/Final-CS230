#include "main.hpp"

int main() {
    BinaryTree tree;

    const int numValues = 10; 
    const int minValue = 1;   
    const int maxValue = 100; 


    cout << "Inserting random values into the binary tree:\n";
    for (int i = 0; i < numValues; ++i) {
        tree.insertRandom(minValue, maxValue);
    }

    
    cout << "\nBinary tree in-order traversal:\n";
    tree.printInOrder();

    return 0;
}