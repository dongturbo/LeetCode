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
