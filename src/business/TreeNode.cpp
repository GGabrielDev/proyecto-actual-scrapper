#include "TreeNode.h"

TreeNode::TreeNode(const char* url) : children(new LinkedList()) {
    int length = stringLength(url) + 1;  // +1 for the null terminator
    this->url = new char[length];
    copyString(this->url, url, length);
}

TreeNode::~TreeNode() {
    delete[] url;  // Free the dynamically allocated memory
    delete children;
}

void TreeNode::addChild(TreeNode* child) {
    children->add(static_cast<void*>(child));
}

const char* TreeNode::getUrl() const {
    return url;
}

LinkedList* TreeNode::getChildren() const {
    return children;
}
