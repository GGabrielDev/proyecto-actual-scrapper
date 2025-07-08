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

LinkStats NavigationTree::computeStats(const char* domain) const {
    LinkStats stats = {0, 0, 0, 0};
    computeStatsRecursive(root, domain, 0, stats);
    return stats;
}

void NavigationTree::computeStatsRecursive(TreeNode* node, const char* domain, int depth, LinkStats& stats) {
    if (!node) return;

    ++stats.total;
    if (depth > stats.maxDepth) {
        stats.maxDepth = depth;
    }

    // Verificar si es interno
    bool isInternal = true;
    int domainLen = stringLength(domain);
    int urlLen = stringLength(node->url);

    if (urlLen < domainLen) {
        isInternal = false;
    } else {
        for (int i = 0; i < domainLen && isInternal; ++i) {
            if (node->url[i] != domain[i]) {
                isInternal = false;
            }
        }
    }

    if (isInternal) ++stats.internal;
    else ++stats.external;

    for (int i = 0; i < node->children->size(); ++i) {
        TreeNode* child = static_cast<TreeNode*>(node->children->get(i));
        computeStatsRecursive(child, domain, depth + 1, stats);
    }
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
