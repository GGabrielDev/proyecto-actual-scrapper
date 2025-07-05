#include <cassert>
#include <iostream>
#include "TreeNode.h"

void testTreeNode() {
    TreeNode node("http://example.com");
    assert(compareString(node.getUrl(), "http://example.com") == 0);

    TreeNode child1("http://example.com/child1");
    TreeNode child2("http://example.com/child2");

    node.addChild(&child1);
    node.addChild(&child2);

    LinkedList* children = node.getChildren();
    assert(children->size() == 2);
}

int main() {
    testTreeNode();
    std::cout << "All TreeNode tests passed!" << std::endl;
    return 0;
}
