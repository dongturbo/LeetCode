/*解题思路:
	1.和上一题比较类似，也是递归实现，上一题是只有递归的层数等于k时，才把结果添加到result中；而本题是每递归一层都把结果添加到result中。
	2.题目要求结果递增，因此在递归前先把nums排序。
*/
void recurCombine(vector<vector<int>> &result, vector<int> & nums, vector<int> &temp, int nth){
	for (int i = nth; i < nums.size(); i++){
		temp.push_back(nums[i]);
		result.push_back(temp);
		recurCombine(result, nums,  temp, i + 1);	
		temp.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> numSet, temp;
	sort(nums.begin(),nums.end());
	result.push_back(temp);
	recurCombine(result, nums,  temp, 0);
	return result;
}