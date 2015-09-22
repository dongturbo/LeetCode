int maxArea(vector<int>& height) {
	int maxArea = 0;
	int i = 0, j = height.size() - 1;
	while (i < j){
		int temp = (j - i)*(height[i]>height[j] ? height[j] : height[i]);
		if (height[i] < height[j]){
			i++;
		}
		else{
			j--;
		}
		if (maxArea < temp)
		{
			maxArea = temp;
		}
	}
	return maxArea;
}