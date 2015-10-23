/*题目的意思是：数组中的每个数是一步从当前下标能跳的最远距离，然后计算从头到尾最少的步数。
解题思路为：
	1.步数最少即要求每步跳尽可能的远。
	2.每步往后跳时都要计算出要跳的那个节点，这个节点必须满足在上一个节点所能跳的范围内，且能跳的最远。
*/
int jump(vector<int>& nums) {
	int length = nums.size();
	if (length == 1)
		return 0;
	int count = 0,i=0;
	while (i < length){
		if (i + nums[i] >= length-1){
			return count+1;
		}
		int maxRange = i + 1;
		for (int j = i+1; j <= i+nums[i]; j++){
			if (maxRange + nums[maxRange] < j + nums[j])
				maxRange = j;
		}
		i = maxRange;
		count++;
	}

}