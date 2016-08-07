//跟上一个层级遍历一样，最后把结果翻转一下
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> result;
    vector<int> temp;
    TreeNode* last=root;
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node==NULL){
            if(!temp.empty())
                result.push_back(temp);
            if(last!=NULL)
                q.push(NULL);
            temp.clear();
        }else{
            temp.push_back(node->val);
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
        last=node;
    }
    reverse(result.begin(),result.end());
    return result;
}
