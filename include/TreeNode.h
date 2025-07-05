#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "LinkedList.h"
#include "StringUtils.h"

class TreeNode {
public:
    TreeNode(const char* url);
    ~TreeNode();

    void addChild(TreeNode* child);
    const char* getUrl() const;
    LinkedList* getChildren() const;

private:
    char url[256];  // Assuming a max URL length of 255 characters
    LinkedList* children;
};

#endif // TREE_NODE_H
