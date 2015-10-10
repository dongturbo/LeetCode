/*
第一种方法用二分查找，分别查找第一个等于target的元素和最后一个等于target的元素。因此此方法的时间复杂度为2*log(n);
*/
vector<int> searchRange(vector<int>& nums, int target) {
	int length = nums.size();
	int left = 0, right = length - 1;
	bool hasFindLeft = false;
	vector<int> range;
	while (left <= right){
		int mid = (left + right) / 2;
		if (nums[mid] == target){
			if (!hasFindLeft){
				if (mid == 0||mid - 1 >= 0 && nums[mid - 1] != target ){
					range.push_back(mid);
					hasFindLeft = true;
					right = length - 1;
					left = mid;
				}
				else if (mid - 1 == 0 && nums[mid - 1] == target){
					range.push_back(mid - 1);
					hasFindLeft = true;
					right = length - 1;
					left = mid;
				}
				else{
					right = mid - 1;
				}
			}
			else{
				if (mid==length-1||mid + 1 < length && nums[mid + 1] != target ){
					range.push_back(mid);
					return range;
				}
				else if(mid+1==length-1 && nums[mid+1]==target){
					range.push_back(mid + 1);
					return range;
				}
				else {
					left = mid + 1;
				}
			}
		}		
		else if (nums[mid] > target){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return { -1, -1 };
}

/*
第二种方法是：
	一个循环中同时查找第一个等于target的元素和最后一个等于target的元素，
	这里需要留意的就是循环完后的left和right的位置，利用>或者>=号来控制循环完后两者所在的位置。
*/
vector<int> searchRange(vector<int>& nums, int target) {
	int length = nums.size();
	vector<int> result;
	int lLeft = 0, lRight = length - 1;
	int rLeft = 0, rRight = length - 1;
	while (lLeft <= lRight || rLeft<=rRight){
		int lMid = (lLeft + lRight)/2;
		int rMid = (rLeft + rRight) / 2;
		if (lLeft <= lRight){
			if (nums[lMid] < target) { 
				lLeft = lMid + 1;
			}
			else{
				lRight = lMid - 1;
			}
		}		
		if (rLeft <= rRight){
			if (nums[rMid] > target) { 
				rRight = rMid - 1;
			}
			else{
				rLeft = rMid + 1;
			}
		}
	}
	//判断是否存在等于target的数，等于的话既是要查找的那个
	if (lLeft<length&&nums[lLeft] == target){
		result.push_back(lLeft);
	}
	if (rRight>=0&&nums[rRight] == target){
		result.push_back(rRight);
	}
	if (result.empty()){
		return{ -1, -1 };
	}
	else{
		return result;
	}
	
}