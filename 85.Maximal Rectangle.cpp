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
			for (; k < colLen && matrix[i][k] == '1'; k++){
				maxArea = maxArea<(k - j + 1) ? (k - j + 1) : maxArea;
			}
			if (k == j)
				continue;
			for (int l = i + 1; l < rowLen && matrix[l][j] == '1'; l++){
				int m = j;
				for (; m < k && matrix[l][m] == '1'; m++){
					int area = (l - i + 1)*(m-j+1);
					maxArea = maxArea > area ? maxArea : area;
				}
				k = m ;
			}
			k = j;
		}
	}
	
	return maxArea;
}