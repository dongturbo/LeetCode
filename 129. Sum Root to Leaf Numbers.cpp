//利用dfs递归遍历，然后把每次的值存储下来，最终计算出结果。
void dfsSum(TreeNode* root, int temp, int &sum){
  	if (root == nullptr)
  		return;
  	temp =temp*10+ root->val;
  	if (root->left == nullptr && root->right == nullptr){
  		sum += temp;
  		return;
  	}
  	if (root->left){
  		dfsSum(root->left, temp , sum);
  	}
  	if (root->right){
  		dfsSum(root->right, temp, sum);
  	}
  }
  
  int sumNumbers(TreeNode* root) {
  	int sum = 0, temp = 0;
  	dfsSum(root, temp, sum);
  	return sum;
  }
