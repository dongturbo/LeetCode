/*解题思路：
	和上一道螺旋打印类似，不过过程恰好相反，循环过程中给matrix赋值。
*/
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n,vector<int>(n));
	int mid = n / 2,  lastSpace = 0;
	for (int i = 0; i < mid; i++){
		int len = n - i - i - 1;
		for (int j = i; j < n - i - 1; j++){
			matrix[i][j] = lastSpace + j - i+1;
			matrix[j][n - i - 1] = lastSpace + j - i + len+1;
			matrix[n - i - 1][n - j - 1] = lastSpace + j - i + 2 * len+1;
			matrix[n - j - 1][i] = lastSpace + j - i + 3 * len+1;
		}
		lastSpace += 4 * len;
	}
	if (n % 2 == 1){
		matrix[mid][mid] = n*n;
	}
	return matrix;
}