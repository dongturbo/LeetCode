//利用hash表，存储一遍所有的数据，并把数据累加，这个和的二倍减去所有数据累加的和即使只出现一遍的数据
int singleNumber(vector<int>& nums) {
	unordered_set<int> set;
	long sum = 0, singleSum = 0;
	for (int i = 0; i<nums.size(); i++){
		if (set.find(nums[i]) == set.end()){
			set.insert(nums[i]);
			singleSum += nums[i];
		}
		sum += nums[i];
	}
	return 2 * singleSum - sum;
}

//利用异或，因为出现两次的异或为0，所以只要把所有都异或一遍剩余的数即为只出现一次的数据
int singleNumber(vector<int>& nums) {
    int result=nums[0];
    for(int i=1;i<nums.size();i++)
        result^=nums[i];
    return result;
}
