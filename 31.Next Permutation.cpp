/*
题目的要求是：
	1.找出nums组成的数据序列中比输入的这个序列大的所有数据序列中最小的那个。
	2.若找不到的话，就把输入的这个序列按升序排序
解题思路：
	1.从序列的最后开始向前比，设置个下标i，把i后面比nums[i]大的元素记录下来，如果没有的话i递减
	2.找出比nums[i]大的集合中最小的那个元素与nums[i]交换。
	3.交换后把此集合中的元素按升序排序，此时得到的结果就是所需的结果。
*/
void nextPermutation(vector<int>& nums) {
	int i ;
	for (i = nums.size()-2; i >=0; i--){
		int min = 2147483647,minIndex;
		//判断nums[i]后面的元素是否比nums[i]大
		for (int j = nums.size() - 1; j > i; j--){			
			if (nums[i] < nums[j]){
				//min记录比nums[i]大的元素中最小的那个
				if (min > nums[j]){
					min = nums[j];
					minIndex = j;
				}
			}
		}
		//如果出现比nums[i]小的元素则交换，并停止循环。
		if (min != 2147483647){
			int temp = nums[i];
			nums[i] = nums[minIndex];
			nums[minIndex] = temp;
			break;
		}
	}
	//把相应的元素按升序排序
	for(int k = i + 1; k < nums.size(); k++){
		for (int l = k; l < nums.size(); l++){
			if (nums[k] > nums[l]){
				int temp = nums[k];
				nums[k] = nums[l];
				nums[l] = temp;
			}
		}
	}
	return;
}