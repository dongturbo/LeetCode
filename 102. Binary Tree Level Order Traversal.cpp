//利用队列，不过需要加个判断条件，看一行是否已经结束，我在判断的时候每行结束往队列插入NULL节点，遇到NULL节点表示一行结束
vector<vector<int>> levelOrder(TreeNode* root) {
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
  return result;
}
