//利用递归遍历，把最后的结果添加到result中
void hasPathSum(TreeNode* root, int sum,vector<vector<int>> &result,vector<int> &temp ) {
    if(root==NULL)
        return ;
    if(root->left==NULL && root->right==NULL&&root->val==sum ){
            temp.push_back(root->val);
            result.push_back(temp);
            temp.pop_back();
            return;
    }
    temp.push_back(root->val);
    if(root->left!=NULL)      
        hasPathSum(root->left,sum-root->val,result,temp);       
    if(root->right!=NULL)
        hasPathSum(root->right,sum-root->val,result,temp);
    temp.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int> temp;
    hasPathSum(root,sum,result,temp);
    return result;
}
