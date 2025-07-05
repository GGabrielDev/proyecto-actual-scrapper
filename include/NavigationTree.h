#ifndef NAVIGATION_TREE_H
#define NAVIGATION_TREE_H

#include "TreeNode.h"

class NavigationTree {
public:
    NavigationTree();
    ~NavigationTree();

    TreeNode* getRoot() const;
    void addNode(const char* url, TreeNode* parent);
    void exportToFile(const char* filename) const;

private:
    TreeNode* root;
};

#endif // NAVIGATION_TREE_H
