/*
根据题目应该是考察二分查找的，但是题目比较水，直接循环也能通过。
第一种方法即直接循环
*/
int search(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
			return i;
	}
	return -1;
}


/*
第二中方法即用到二分查询，不过判断过程比较复杂。
*/
int search(vector<int>& nums, int target) {
	int length = nums.size();
	int left = 0, right = length - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[left]<nums[right]){
			if (nums[mid]>target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		else if (nums[left]<=nums[mid]){
			if (target > nums[mid] || target < nums[left])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else{
			if (target<nums[mid] || target>nums[right])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}


	return -1;
}