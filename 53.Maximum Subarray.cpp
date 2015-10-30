/*解题思路：
	初始设sum=0，然后进行循环，如果sum+nums[i]>nums[i]的话sum=sum+nums[i],否则sum=nums[i],然后设maxSum保存最大sum即可.
*/
int maxSubArray(vector<int>& nums) {
	int length = nums.size();
	int maxSum = INT_MIN, sum = 0;
	for (int i = 0; i < length; i++){
		if (sum + nums[i] > nums[i]){
			sum = sum + nums[i];
		}
		else{
			sum = nums[i];
		}
		if (maxSum<sum)
			maxSum = sum;
	}
	return maxSum;
}
