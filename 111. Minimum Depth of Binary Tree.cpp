int minDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    if(root->left==NULL)
        return minDepth(root->right)+1;
    if(root->right==NULL)
        return minDepth(root->left)+1;
    if(root->left!=NULL && root->right!=NULL)
        return min(minDepth(root->left),minDepth(root->right))+1;
    return 1;
}
