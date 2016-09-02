//利用深度优先搜索遍历
void dfs(TreeNode* root,vector<string> &result,string t){
    if(root==nullptr)
        return;
    if(root->left==nullptr && root->right==nullptr){
        result.push_back(t+to_string(root->val));
    }
    dfs(root->left,result,t+to_string(root->val)+"->");
    dfs(root->right,result,t+to_string(root->val)+"->");
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    dfs(root,result,"");
    return result;
}
