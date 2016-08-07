//跟上一题类似，主要在于分割左右子树
TreeNode* buildChildTree(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd,int postBegin, int postEnd){
	if (postBegin >= postEnd){
		return NULL;
	}
	int rootVal = postorder[postEnd-1], rootRange = 0;
	TreeNode* root = new TreeNode(rootVal);
	for (int i = inBegin; i < inEnd; i++){
		if (inorder[i] == rootVal){
			rootRange = i-inBegin;
			break;
		}
	}
	root->left = buildChildTree(inorder, postorder, inBegin, inBegin + rootRange, postBegin, postBegin  + rootRange);
	root->right = buildChildTree(inorder, postorder, inBegin + rootRange + 1, inEnd, postBegin  + rootRange, postEnd - 1);
	return root;
}
 
TreeNode* buildTree( vector<int>& inorder, vector<int>& postorder) {
	return buildChildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
}
