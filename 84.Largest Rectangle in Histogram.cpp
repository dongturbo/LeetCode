/*解题思路：
	参考的这篇博客：http://www.cnblogs.com/felixfang/p/3676193.html
*/
int largestRectangleArea(vector<int> &height) {
	stack<int> index;
	height.push_back(0);
	int maxArea = 0;
	for (int i = 0; i < height.size(); i++) {
		if (index.empty() || height[i] > height[index.top()]) 
			index.push(i);
		else {
			int tmp = index.top();
			index.pop();
			maxArea = max(maxArea, height[tmp] * (index.empty() ? i : i - index.top() - 1));
			i--;
		}
	}
	return maxArea;
}