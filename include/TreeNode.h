#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "LinkedList.h"
#include "StringUtils.h"

class TreeNode {
public:
    TreeNode(const char* url);
    ~TreeNode();

    LinkedList* children;
    char* url;

    void addChild(TreeNode* child);
    const char* getUrl() const;
    LinkedList* getChildren() const;
};

#endif // TREE_NODE_H
