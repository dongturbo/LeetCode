//方案一：通过set去重，计算set的总和和sum的和，然后计算出只出现一次的那个
int singleNumber(vector<int> &nums) {
    set<int> sets;
    long sum = 0, setSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(sets.find(nums[i])==sets.end()){
            sets.insert(nums[i]);
            setSum+=nums[i];
        }
    }
    return (setSum*3-sum)/2;
}
//方案二：通过对nums排序，然后按照顺序，遍历一遍即可判断出
int singleNumber(vector<int>& nums) {
  if (nums.size() == 1)
		return nums[0];
	sort(nums.begin(), nums.end());
	if (nums[0] != nums[1])
		return nums[0];
	for (size_t i = 1; i < nums.size() - 1; ++i)
	{
		if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
			return nums[i];
	}
	return nums.back();
}
