#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.hpp"

TEST_CASE("BinaryTree: Insert Random Values", "[insertRandom]") {
    BinaryTree tree;

    const int numValues = 5;
    const int minValue = 10;
    const int maxValue = 20;

    for (int i = 0; i < numValues; ++i) {
        tree.insertRandom(minValue, maxValue);
    }

    REQUIRE_NOTHROW(tree.printInOrder());
}

TEST_CASE("BinaryTree: In-Order Traversal", "[printInOrder]") {
    BinaryTree tree;

    tree.insertRandom(15, 15); 
    tree.insertRandom(10, 10); 
    tree.insertRandom(20, 20); 

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    tree.printInOrder();
    std::cout.rdbuf(oldCoutBuffer);

    REQUIRE(output.str() == "10 15 20 \n");
}

TEST_CASE("BinaryTree: Destructor and Memory Cleanup", "[destructor]") {
    BinaryTree* tree = new BinaryTree();

    tree->insertRandom(1, 10);
    tree->insertRandom(11, 20);
    tree->insertRandom(21, 30);

    REQUIRE_NOTHROW(delete tree);
}
