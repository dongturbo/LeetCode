//由于此题不要求计算完的数组的长度比原先大，因此只要保证计算完的数组的前N项是删除后的数组的数据就行
//此题和26题特别像，可以利用上题一样的思路，即pos下标来保存删除后的数据，这样循环一遍即把nums的前pos项内容变成已删除element的数组
int removeElement(vector<int>& nums, int val) {
	int length = nums.size(),pos=0;
	if (nums.empty())
		return 0;
	for (int i = 0; i < length; i++){
		if (nums[i] != val){
			nums[pos++] = nums[i];
		}
	}
	return pos;
}