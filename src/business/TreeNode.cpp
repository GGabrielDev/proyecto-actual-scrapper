#include "TreeNode.h"

TreeNode::TreeNode(const char* url) : children(new LinkedList()) {
    copyString(this->url, url, sizeof(this->url));
}

TreeNode::~TreeNode() {
    delete children;
}

void TreeNode::addChild(TreeNode* child) {
    children->add(static_cast<void*>(child)); // Store pointer as void*
}

const char* TreeNode::getUrl() const {
    return url;
}

LinkedList* TreeNode::getChildren() const {
    return children;
}
