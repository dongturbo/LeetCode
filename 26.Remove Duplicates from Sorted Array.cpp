//第一种方法利用迭代器删除重复的项即可
int removeDuplicates(vector<int>& nums) {
	int count,i;
	if (nums.empty()){
		return 0;
	}
	vector<int>::iterator it,temp;
	for (it=nums.begin()+1, count = 1; it!=nums.end(); it++){
		if (*it!=*(it-1)){
			count++;
		}
		else{
			temp = it - 1;
			nums.erase(it);
			it = temp;
		}
	}
	return count;
}

//第二中方法是直接用数组形式来计算，不删除元素，pos记录非重复元素的个数，并且把依次把nums中的非重复元素
//放到nums的前pos项，这种方法时间上提高不少
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<=1) return n;
        
        int pos=0;
        for(int i=0; i<n-1; i++){
            if (nums[i]!=nums[i+1]){
                nums[++pos] = nums[i+1];
            }
        }
        return pos+1;
    }