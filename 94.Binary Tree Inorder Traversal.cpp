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
/*利用栈实现，不用递归
*/