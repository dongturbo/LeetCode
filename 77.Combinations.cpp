/*解题思路：
	1.利用递归遍历，每递归深入一层，就添加一个数，当层数和k相等时返回。
	2.为了保证不出重复的结果，第i+1层遍历是在第i层已遍历的数的下一个开始循环，这样遍历完即为正确结果。
*/
void recurCombine(vector<vector<int>> &result, int n, int k, int level, vector<int> &temp,int nth){
	for (int i = nth; i < n;i++){		
		temp.push_back(i+1);
		recurCombine(result,n,k,level+1,temp,i+1);
		if (level+1==k)
			result.push_back(temp);
		temp.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;
	vector<int> numSet,temp;
	if (n < k){
		return result;
	}
	recurCombine(result,n,k,0,temp,0);
	return result;
}