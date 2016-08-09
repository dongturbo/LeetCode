//创建函数flat，让其返回当前子树的前序遍历的最后一个节点，把这个子树的父节点的右子树的根赋值给这个节点的的右孩子。
TreeNode* flat(TreeNode* root) {
    if(root==NULL)
        return NULL;
    TreeNode* leftNode=root->left;
    TreeNode* rightNode=root->right;
    if(leftNode==NULL &&rightNode==NULL){
        return root;
    }
    else if(leftNode==NULL){
        return flat(root->right);
    }else if(rightNode==NULL){
        root->right=leftNode;
        root->left=NULL;
        return flat(leftNode);
    }else{
        root->right=leftNode;
        root->left=NULL;
        TreeNode* endNode=flat(leftNode);
        endNode->right=rightNode;
        return flat(rightNode);
    }
}
void flatten(TreeNode* root) {
    flat(root);    
}
