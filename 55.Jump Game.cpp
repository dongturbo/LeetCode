//nums中最远能跳到的距离只要能跳到最后说明成功，最远能跳到的距离小于length时即为false
bool canJump(vector<int>& nums) {
	int length = nums.size();
	int curMax = 0;
	int i = 0;
	while (i < length && i<=curMax )
	{
		curMax = max(curMax, nums[i] + i);
		i++;
	}
	return i==length;
}