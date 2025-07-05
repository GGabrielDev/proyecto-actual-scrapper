#include <cassert>
#include <iostream>
#include "NavigationTree.h"

void testNavigationTree() {
    NavigationTree tree;
    tree.addNode("http://example.com", nullptr);

    TreeNode* root = tree.getRoot();
    assert(root != nullptr);
    assert(compareString(root->getUrl(), "http://example.com") == 0);

    tree.addNode("http://example.com/child1", root);
    assert(root->getChildren()->size() == 1);
}

int main() {
    testNavigationTree();
    std::cout << "All NavigationTree tests passed!" << std::endl;
    return 0;
}
