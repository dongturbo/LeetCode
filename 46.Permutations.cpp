/*
建立一棵树，对于第k层节点来说，就是交换固定了前面 k-1 位，然后分别 swap(k,k), swap(k, k+1) , swap(k, k+2) ...
*/
void levelSwap(vector<vector<int>>& result, vector<int>& nums, int level){
	int length = nums.size();
	if (level + 1 == length){
		result.push_back(nums);
		return;
	}
	for (int i = level; i < length; i++){
		int temp = nums[level];
		nums[level] = nums[i];
		nums[i] = temp;
		levelSwap(result, nums, level+1);
		temp = nums[level];
		nums[level] = nums[i];
		nums[i] = temp;
	}
	
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> result;
	levelSwap(result, nums, 0);
	return result;
}