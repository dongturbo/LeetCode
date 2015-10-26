//和上一题比较类似，但是得判断重复的交换，如果重复，则不用交换
bool isSwap(vector<int>& num, int s, int e) {
	int i = s;
	while (num[i] != num[e] && i < e) 
		i++;
	if (i == e) 
		return true;
	else 
		return false;
}
void levelSwap(vector<vector<int>>& result, vector<int>& nums, int level,int length){
	if (level + 1 == length){
		result.push_back(nums);
		return;
	}
	for (int i = level; i < length; i++){
		if (!isSwap(nums, level, i)){
			continue;
		}
		int temp = nums[level];
		nums[level] = nums[i];
		nums[i] = temp;
		levelSwap(result, nums, level+1,length);
		temp = nums[level];
		nums[level] = nums[i];
		nums[i] = temp;
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> result;
	int length = nums.size();
	sort(nums.begin(), nums.end());
	levelSwap(result, nums, 0, length);
	return result;
}