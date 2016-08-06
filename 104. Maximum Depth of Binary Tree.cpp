//利用栈迭代，栈的最大长度即为最大深度
int maxDepth(TreeNode* root) {
	stack<TreeNode*> stack;
	stack.push(root);
	if (root == NULL)
		return 0;
	int depth=0;
	while (!stack.empty()){
		TreeNode* temp = stack.top();
		if (stack.size() > depth)
			depth = stack.size();
		if (temp->left){
			stack.push(temp->left);
		}
		else if(temp->right){
			stack.push(temp->right);
		}
		else{
			stack.pop();
			while (!stack.empty()){
				if (stack.top()->right != NULL && stack.top()->right != temp){
					stack.push(stack.top()->right);
					break;
				}			
				else{
					temp = stack.top();
					stack.pop();
				}
					
			}
		}
	}
	return depth;
}
//利用递归遍历
int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left != NULL && root->right!=NULL){
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		if (leftDepth>rightDepth)
			return leftDepth + 1;
		else
			return rightDepth + 1;
	}
	else if (root->left==NULL){
		return maxDepth(root->right) + 1;
	}
	else{
		return maxDepth(root->left) + 1;
	}
}
