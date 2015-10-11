//首先扩大nums的为nums.length+1,然后直接循环，如果有相等的话清除添加的空间返回，不相等的话插入进去。
int searchInsert(vector<int>& nums, int target) {
	int length = nums.size();
	int index=length;
	if (length == 0){
		nums.push_back(target);
		return index;
	}
	nums.resize(length+1);
	vector<int>::iterator it;
	for (it = nums.end()-1; it >nums.begin() ; it--,index--){
		if (*(it-1) > target){
			*it = *(it - 1);
			if (it - 1 == nums.begin()){
				*(it - 1) = target;
				index--;
				break;
			}
		}
		else if(*(it-1)==target){
			nums.erase(it);
			index--;
			break;
		}
		else if (*(it - 1) < target){
			*it = target;
			break;
		}
	}
	return index;
}
