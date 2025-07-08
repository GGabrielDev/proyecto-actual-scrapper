#ifndef NAVIGATION_TREE_H
#define NAVIGATION_TREE_H

#include "TreeNode.h"

struct LinkStats {
    int total;
    int internal;
    int external;
    int maxDepth;
};

class NavigationTree {
public:
    NavigationTree();
    ~NavigationTree();

    TreeNode* getRoot() const;
    TreeNode* findNodeRecursive(TreeNode* node, const char* url) const;
    TreeNode* findNode(const char* url) const;
    LinkStats computeStats(const char* domain) const;
    static void computeStatsRecursive(TreeNode* node, const char* domain, int depth, LinkStats& stats);
    void addNode(const char* url, TreeNode* parent);
    void exportToFile(const char* filename) const;
    int countNodes() const;
    int countRecursive(TreeNode* node) const;

private:
    TreeNode* root;
};

#endif // NAVIGATION_TREE_H
