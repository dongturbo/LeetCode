/*  利用递归遍历整个树，即递归遍历左右子树，遍历子树时要确认该子树所在的范围，即在最大值最小值之间，否则返回false.
  遍历时要首先确认该子树的最大值和最小值。
*/
bool isValidTrees(TreeNode* root,TreeNode* min,TreeNode* max){
    if(root==NULL)
        return true;
    if(min!=NULL &&root->val<=min->val || max!=NULL &&root->val>=max->val)
        return false;
    return isValidTrees(root->left,min,root )&& isValidTrees(root->right,root,max);    
}
    
bool isValidBST(TreeNode* root) {
    if(root==NULL)
        return true;
    return isValidTrees(root->left,NULL,root )&& isValidTrees(root->right,root,NULL);
    
}
