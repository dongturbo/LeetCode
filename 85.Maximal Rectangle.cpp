/*解题思路
    1.循环遍历每一个元素，判断是否为1，为1的话执行步骤2，不为1的继续循环
    2.从遍历的元素开始执行循环，遍历该元素所在的行，并找到以该元素开始连续为1的元素长度
    3.还是从该元素开始执行循环，遍历该元素所在的列，并计算连续为1的矩形的面积，循环完后执行步骤1
*/
int maximalRectangle(vector<vector<char>>& matrix) {
	int rowLen = matrix.size();
	if (rowLen == 0)
		return 0;
	int colLen = matrix[0].size();
	int maxArea = 0;
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			int k = j;
			for (; k < colLen && matrix[i][k] == '1'; k++);
			maxArea = maxArea < (k - j + 1) ? (k - j ) : maxArea;
			if (k == j)
				continue;
			for (int l = i + 1; l < rowLen && matrix[l][j] == '1'; l++){
				int m = j;
				for (; m < k && matrix[l][m] == '1'; m++);
				int area = (l - i + 1)*(m - j );
				maxArea = maxArea > area ? maxArea : area;
				k = m;
			}
			k = j;
		}
	}
    
	return maxArea;
}


/* 方法二
搜索后，知道是max histogram这个题目的思想的灵活运用，就是每一行运用max histogram算法思想计算。
原来LeetCode把max histogram放在这一题之前是有原因的。没有max histogram这一题的思想基础垫底，是很难理解的。
LeetCode论坛上的讨论，其实也是这一思想的变种运用，不过感觉讲得并不清楚，他所谓的拖线法，其实就是histogram的倒置。
只不过并没有严格按照histogram的算法来进行，而是优化了。
*/
int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty()) {
		return 0;
	}

	int n = matrix[0].size();
	vector<int> H(n);
	vector<int> L(n);
	vector<int> R(n, n);

	int ret = 0;
	for (int i = 0; i < matrix.size(); ++i) {
		int left = 0, right = n;
		// calculate L(i, j) from left to right
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == '1') {
				++H[j];
				L[j] = max(L[j], left);
			}
			else {
				left = j + 1;
				H[j] = 0; L[j] = 0; R[j] = n;
			}
		}
		// calculate R(i, j) from right to right
		for (int j = n - 1; j >= 0; --j) {
			if (matrix[i][j] == '1') {
				R[j] = min(R[j], right);
				ret = max(ret, H[j] * (R[j] - L[j]));
			}
			else {
				right = j;
			}
		}
	}

	return ret;
}

/*方法三

*/
int maximalRectangle(vector<vector<char> > &matrix) 
{
    if (matrix.empty() || matrix[0].empty()) return 0;
    vector<int> height(matrix[0].size()+1);
    int max_area = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
        max_area = max(max_area, maxHistogram(height));
    }
    return max_area;
}
int maxHistogram(vector<int> &height)
{
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < height.size(); )
    {
        if (stk.empty() || height[stk.top()] < height[i]) stk.push(i++);
        else
        {
            int idx = stk.top();
            stk.pop();
            ans = max(ans, (stk.empty()? i:i-stk.top()-1)*height[idx]);
        }
    }
    return ans;
}