/*跟上一个subset题相似，也是递归，只是需要去重
由于递归每层都有循环，若出现重复元素，只去这一层的第一个元素，保证递归每一层唯一，即结果唯一
*/

void recurSubset(vector<vector<int>>& result, vector<int>& tempRes, vector<int>& nums, int nth){
	for (int i = nth; i < nums.size(); i++){
		if (i != nth && nums[i] == nums[i - 1])
			continue;
		tempRes.push_back(nums[i]);
		result.push_back(tempRes);
		recurSubset(result, tempRes, nums, i + 1);
		tempRes.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<int> tempRes;
	result.push_back(tempRes);
	recurSubset(result,tempRes,nums,0);
	return result;
}