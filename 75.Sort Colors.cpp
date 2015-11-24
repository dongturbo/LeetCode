/*定义一个数组,保存三种颜色的数量，然后再按照统计的数量覆盖原先的数组就行*/
void sortColors(vector<int>& nums) {
	int count[] = {0,0,0};
	for (int i = 0; i < nums.size(); i++){
		count[nums[i]]++;
	}
	for (int i = 0; i < nums.size(); i++){
		if (i < count[0]){
			nums[i] = 0;
		}
		else if (i < count[0] + count[1]){
			nums[i] = 1;
		}
		else{
			nums[i] = 2;
		}
	}
}