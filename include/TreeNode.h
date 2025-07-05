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
    char* url;  // Pointer to dynamically allocated memory
    LinkedList* children;
};

#endif // TREE_NODE_H
