/*
解题思路：
	首先从左向右开始计算，设highest为0，height[i]比highest小的话，把差值累加到temp中，直到height[i]比highest大的话，waterSize累加一次temp，并把highest设为height[i]，并把temp清零。
	这样的话，会把最大height[i]之前的结果雨点数计算出来，但是之后的没有计算。所以再反向计算一次，这样最终的结果即为正确答案。
*/
int trap(vector<int>& height) {
	int length = height.size();
	int waterSize = 0,highest=0,temp=0,isEnd=0;
	for (int i = 0; i < length; i++){
		if (height[i] < highest){
			temp += highest - height[i];
		}
		else{
			highest = height[i];
			waterSize += temp;
			temp = 0;
			isEnd = i;
		}
	}
	highest = 0,temp=0;
	for (int i = length - 1; i >= isEnd; i--){
		if (height[i] < highest){
			temp += highest - height[i];
		}
		else{
			highest = height[i];
			waterSize += temp;
			temp = 0;
		}
	}
	return waterSize;
}