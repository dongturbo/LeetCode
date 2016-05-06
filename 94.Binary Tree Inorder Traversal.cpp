/* 中序遍历，利用递归实现，把每次递归子树看成一棵二叉树，先遍历左边节点，然后根节点，最后右节点，直到递归完成
*/
void recurInorder(TreeNode* root, vector<int> &result){
	if (root->left != nullptr)
		recurInorder(root->left, result);
	result.push_back(root->val);
	if (root->right != nullptr)
		recurInorder(root->right, result);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	if (root == nullptr)
		return result;
	recurInorder(root,result);
	return result;
}
/*不用递归，利用栈迭代实现
*/
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	vector<TreeNode*> stack;
	if (root == nullptr)
		return result;
	while (root != nullptr || !stack.empty()){
		if (root != nullptr)
		{
			stack.push_back(root);
			root = root->left;
		}
		else
		{
			root = stack.back();
			stack.pop_back();
			result.push_back(root->val);
			root = root->right;
		}
	}
	return result;
} 