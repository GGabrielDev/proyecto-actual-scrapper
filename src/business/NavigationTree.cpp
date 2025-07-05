#include "NavigationTree.h"
#include <fstream>

NavigationTree::NavigationTree() : root(nullptr) {}

NavigationTree::~NavigationTree() {
    delete root;
}

TreeNode* NavigationTree::getRoot() const {
    return root;
}

void NavigationTree::addNode(const char* url, TreeNode* parent) {
    TreeNode* newNode = new TreeNode(url);
    if (parent == nullptr) {
        root = newNode;
    } else {
        parent->addChild(newNode);
    }
}

void NavigationTree::exportToFile(const char* filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Simple export logic, can be expanded
        file << "Root URL: " << (root ? root->getUrl() : "None") << "\n";
        file.close();
    }
}
