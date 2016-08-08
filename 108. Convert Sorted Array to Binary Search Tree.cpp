TreeNode* sortedBST(vector<int> &nums,int begin,int end){
    if(begin>=end){
        return NULL;
    }
    int mid=(begin+end)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=sortedBST(nums,begin,mid);
    root->right=sortedBST(nums,mid+1,end); 
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedBST(nums,0,nums.size());
}
