/*解题思路：
	顺时针旋转90度，即把(length-j-1,i)的数据放到(i,j)中，循环四次即替换一圈元素，然后在外层套用循环，使之所有都替换完毕
*/
void rotate(vector<vector<int>>& matrix) {
	int length = matrix.size();
	int mid = (length + 1) / 2;
	for (int i = 0; i < mid; i++){
		for (int j = i; j < length - i - 1; j++){
			int temp = matrix[i][j], m = i, n = j;
			for (int k = 0; k < 3; k++){
				matrix[m][n]=matrix[length-n-1][m];
				int t = m;
				m=length-n-1;
				n = t;
			}
			matrix[m][n] = temp;
		}
	}
}

