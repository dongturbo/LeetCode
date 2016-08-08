//首先判断哪些节点是叶子节点，然后利用递归判断
bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL ){
        if(root->val==sum)
            return true;
        else
            return false;
    }
    return (root->left!=NULL?hasPathSum(root->left,sum-root->val):false)||
        (root->right!=NULL?hasPathSum(root->right,sum-root->val):false); //判断左右子树时，sum记得减去当前节点的val
}
