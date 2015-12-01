//第一种方法：统计nums中数字的出现的次数，把超过两次的部分删除掉，返回nums的长度即可。
int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator it;
	if (nums.size() == 0)
		return 0;
	int count = 0,current=nums[0];
	for (it = nums.begin(); it != nums.end(); ){
		if (current == *it){
			count++;
			if (count > 2){
				if (it + 1 != nums.end()){
					it = nums.erase(it);
				}
				else{
					nums.erase(it);
					break;
				}				
			}
			else
				it++;
		}
		else{
			current = *it;
			count = 1;
			it++;
		}
	}
	return nums.size();
}
//第二种方法：遍历nums数组，把数字添加到result中，超过两次的数字不添加，最后把result赋值给nums即可，并返回result的长度即可。
int removeDuplicates(vector<int>& nums) {
	vector<int> result;
	if (nums.size() == 0)
		return 0;
	int count = 0,current=nums[0];
	for (int i = 0; i < nums.size(); i++){
		if (current == nums[i]){
			count++;
			if (count <= 2){
				result.push_back(nums[i]);
			}
		}
		else{
			current = nums[i];
			result.push_back(nums[i]);
			count = 1;
		}
	}
	nums = result;
	return result.size();
}
//第三种方法是把出现超过三次的数移到后面
int removeDuplicates(vector<int>& nums) {
	if (nums.size() < 3) return nums.size();
	int len = 1;
	int n = 1;
	for (int i = 1; i < nums.size(); i++){
		if (nums[i] != nums[i - 1]){
			nums[len++] = nums[i];
			n = 1;
		}
		else if (n == 1){
			nums[len++] = nums[i];
			n++;
		}
		else
			continue;
	}
	return len;
}