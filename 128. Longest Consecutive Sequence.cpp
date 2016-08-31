//由于要求O(n)
//用一个哈希表UNordered_map<int,bool> used记录元素是否使用，对每个元素，以该元素为中心，往左右扩张，直到不连续为止，记录下最长的长度
int longestConsecutive(vector<int>& nums) {
	int maxLen = 1;
	unordered_map<int, bool> used;
	for (auto num : nums)
		used[num] = false;
	for (auto num : nums){
		if (used[num])
			continue;
		int begin = num,end = num;
		for (end = num; used.find(end)!=used.end(); end++)
			used[end] = true;
		for (begin = num; used.find(begin) != used.end(); begin--)
			used[begin] = true;
		if (end - begin + 1 > maxLen)
			maxLen = end - begin + 1;
	}
	return maxLen;
}

//利用union，find操作，连续序列可以用两端和长度来表示。用unordered_map<int,int> map,来存储
int longestConsecutive(vector<int> &nums) {
	unordered_map<int, int> map;
	int size = nums.size();
	int l = 1;
	for (int i = 0; i < size; i++) {
		if (map.find(nums[i]) != map.end()) continue;
		map[nums[i]] = 1;
		if (map.find(nums[i] - 1) != map.end()) {
			l = max(l, mergeCluster(map, nums[i] - 1, nums[i]));
		}
		if (map.find(nums[i] + 1) != map.end()) {
			l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
		}
	}
	return size == 0 ? 0 : l;
}

int mergeCluster(unordered_map<int, int> &map, int left, int right) {
	int upper = right + map[right] - 1;
	int lower = left - map[left] + 1;
	int length = upper - lower + 1;
	map[upper] = length;
	map[lower] = length;
	return length;
}
