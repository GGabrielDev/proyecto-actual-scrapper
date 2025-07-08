#ifndef NAVIGATION_TREE_H
#define NAVIGATION_TREE_H

#include "TreeNode.h"

class NavigationTree {
public:
    NavigationTree();
    ~NavigationTree();

    TreeNode* getRoot() const;
    TreeNode* findNodeRecursive(TreeNode* node, const char* url) const;
    TreeNode* findNode(const char* url) const;
    void addNode(const char* url, TreeNode* parent);
    void exportToFile(const char* filename) const;
    int countNodes() const;
    int countRecursive(TreeNode* node) const;

private:
    TreeNode* root;
};

#endif // NAVIGATION_TREE_H
