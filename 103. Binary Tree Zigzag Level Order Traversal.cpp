//加了个反转函数，依次反转
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> result;
    vector<int> temp;
    bool isReverse=false;;
    TreeNode* last=root;
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node==NULL){
            if(!temp.empty()){
                if(isReverse){
                    reverse(temp.begin(),temp.end());
                    isReverse=false;
                }else
                    isReverse=true;
                result.push_back(temp);   
            }
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
    return result;
}
