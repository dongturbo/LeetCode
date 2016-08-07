//利用递归，每次递归把节点分到左右子树中
TreeNode* buildChildTree(vector<int>& preorder, vector<int>& inorder,int preBegin,int preEnd ,int inBegin, int inEnd){
	if (preBegin >= preEnd){
		return NULL;
	}
	int rootVal = preorder[preBegin], rootRange = 0;
	TreeNode* root = new TreeNode(rootVal);
	for (int i = inBegin; i < inEnd; i++){
		if (inorder[i] == rootVal){
			rootRange = i-inBegin;
			break;
		}
	}
	root->left = buildChildTree(preorder, inorder, preBegin + 1, preBegin + rootRange+1,inBegin,inBegin+rootRange);
	root->right = buildChildTree(preorder, inorder, preBegin + rootRange + 1, preEnd, inBegin + rootRange+1,inEnd);
	return root;
}
 
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	return buildChildTree(preorder, inorder, 0, preorder.size(), 0, preorder.size());
}
