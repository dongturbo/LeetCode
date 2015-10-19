//第一种方法先排序，后遍历大于0的项，只要不连续即返回，虽然提交能通过，但并不符合O(n)的要求，时间复杂度为n(log(n)).
int firstMissingPositive(vector<int>& nums) {
	int length = nums.size();
	sort(nums.begin(), nums.end());
	int k = 1;
	for (int i = 0; i < length; i++){
		if (nums[i] > 0){
			if (nums[i] != k){
				return k;
			}
			if (i+1 < length&&nums[i + 1] == k){
				continue;
			}	
			k++;
		}
		
	}
	return k;
}

/*
交换数组元素，使得数组中第i位存放数值(i+1)。
最后遍历数组，寻找第一个不符合此要求的元素，返回其下标。整个过程需要遍历两次数组，复杂度为O(n)。
*/

int firstMissingPositive(vector<int>& nums) {
	int length = nums.size();
	int i = 0;
	while (i < length){
		if (nums[i] > 0 && nums[i] < length && nums[i] != nums[nums[i]-1]){
			int temp = nums[i];
			nums[i] = nums[temp-1];
			nums[temp-1] = temp;
		}
		else{
			i++;
		}
	}
	for (i = 0; i < length; i++){
		if (i+1 != nums[i])
			return i+1;
	}
	return i+1;
}