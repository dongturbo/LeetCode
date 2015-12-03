/*解题思路：
	和之前那道题类似，在遇到nums中存在多个相同元素的元素为锚点时，需要移到不相同的元素再检索。
*/
bool search(vector<int>& nums, int target) {
	int length = nums.size();
	if (length == 0)
		return false;
	int low = 0, high = length - 1;
	while (low<=high){
		int mid = (low + high) / 2;
		if (nums[mid] == target)
			return true;
		if (nums[low] > nums[mid]){
			if (target >= nums[low] || target<nums[mid]){
				high = mid - 1;
			}
			else if (target >= nums[mid] && target <=nums[high]){
				low = mid + 1;
			}
			else
				return false;
		}
		else if (nums[low] < nums[mid]){
			if (target >= nums[low] && target < nums[mid])
				high = mid - 1;
			else if (target > nums[mid] || target <= nums[high])
				low = mid + 1;
			else
				return false;
		}
		else{
			while (nums[low] == nums[mid])
				low++;
		}
	}
	return false;
}