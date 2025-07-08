#include "NavigationTree.h"
#include <iostream>
#include <fstream>

NavigationTree::NavigationTree() : root(nullptr) {}

NavigationTree::~NavigationTree() {
    delete root;
}

TreeNode* NavigationTree::getRoot() const {
    return root;
}

TreeNode* NavigationTree::findNodeRecursive(TreeNode* node, const char* url) const {
    if (!node) return nullptr;
    if (compareString(node->url, url) == 0) return node;

    for (int i = 0; i < node->children->size(); ++i) {
        TreeNode* result = findNodeRecursive(static_cast<TreeNode*>(node->children->get(i)), url);
        if (result) return result;
    }
    return nullptr;
}

TreeNode* NavigationTree::findNode(const char* url) const {
    return findNodeRecursive(root, url);
}

void NavigationTree::addNode(const char* url, TreeNode* parent) {
    TreeNode* newNode = new TreeNode(url);

    if (parent == nullptr) {
        if (root == nullptr) {
            root = newNode; // Primera llamada: se establece raíz
        } else {
            // Error: ya hay raíz definida, no puede haber más de una
            delete newNode;
            return;
        }
    } else {
        parent->addChild(newNode);
    }
    std::cout << "[DEBUG] addNode called for: " << url << std::endl;
}

void NavigationTree::exportToFile(const char* filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Simple export logic, can be expanded
        file << "Root URL: " << (root ? root->getUrl() : "None") << "\n";
        file.close();
    }
}

int NavigationTree::countNodes() const {
    return countRecursive(root);
}

int NavigationTree::countRecursive(TreeNode* node) const {
    if (!node) return 0;
    int total = 1;
    for (int i = 0; i < node->children->size(); ++i) {
        total += countRecursive(static_cast<TreeNode*>(node->children->get(i)));
    }
    return total;
}
