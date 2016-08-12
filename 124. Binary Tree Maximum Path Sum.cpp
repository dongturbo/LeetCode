/*利用递归遍历，maxSum返回当前节点为根的最大和，遍历整个树
*/

//函数返回当前节点为根的最大和
int maxSum(TreeNode* root,int &sum){
    if(root==NULL)
        return INT_MIN;
    sum=root->val>sum?root->val:sum;
    int leftSum=maxSum(root->left,sum);
    int rightSum=maxSum(root->right,sum);
    leftSum=leftSum>0?leftSum:0;  //若左子树和为负数，就直接设为0
    rightSum=rightSum>0?rightSum:0; //和左子树相同
    sum=max(leftSum+root->val+rightSum,sum);
    return root->val+max(leftSum,rightSum);
}

int maxPathSum(TreeNode* root) {
    int sum=INT_MIN; //保存最大值
    maxSum(root,sum);
    return sum;
}
