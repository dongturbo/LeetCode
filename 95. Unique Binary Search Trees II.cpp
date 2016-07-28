 /*利用分治思想
    1.从0-n中选取i为根节点，那么i的左右子树种类个数的乘积，即以i为根节点形成树种类的个数
    2.递归的计算以i为根节点的左右子树的个数，重复第一步，直到左右子树为空为止
 */
 vector<TreeNode*> recurGenerate(int begin,int end){
    	vector<TreeNode* > ret;
    	if(begin>end){
    		ret.push_back(NULL);
    		return ret;
    	}
    	for(int i=begin;i<=end;i++){
    		vector<TreeNode* > leftTrees=recurGenerate(begin,i-1);
    		vector<TreeNode* > rightTrees=recurGenerate(i+1,end);
    		for(int j=0;j<leftTrees.size();j++){
    			for(int k=0;k<rightTrees.size();k++){
    				TreeNode *node = new TreeNode(i + 1);
    				ret.push_back(node);
    				node->left=leftTrees[j];
    				node->right=rightTrees[k];
    			}
    		}
    	}
    	return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
    	if(n==0)
    		return vector<TreeNode*>();
    	else
    	    return	recurGenerate(0,n-1);
    }
