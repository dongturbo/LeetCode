/*按照题目要求利用常数的空间进行计算,解题思路
	1.首先扫描第一行和第一列并设个两个变量来保存第一行和第一列是否为0的状态，
	2.然后扫描剩下的元素，把为零的行和列的状态都保存到matrix的第一行和第一列中，
	3.在扫描第一行和第一列把为0的行和列全置为0.
	4.按照两个保存第一行和第一列状态的变量来重置第一行和第一列。
*/
void setZeroes(vector<vector<int>>& matrix) {
	int rowLen = matrix.size();
	if (rowLen == 0)
		return;
	int colLen = matrix[0].size();
	int rFirst=-1,cFirst=-1;
	for (int i = 0; i < rowLen; i++){
		if (matrix[i][0] == 0){
			cFirst = 0;
			break;
		}
	}
	for (int i = 0; i < colLen; i++){
		if (matrix[0][i] == 0){
			rFirst = 0;
			break;
		}
	}
	for (int i = 1; i < rowLen; i++){
		for (int j = 1; j < colLen; j++){
			if (matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for (int i = 1; i < rowLen || i < colLen; i++){
		int rowSign = -1, colSign = -1;
		if (i < rowLen)
			rowSign = matrix[i][0];
		if (i < colLen)
			colSign = matrix[0][i];
		if (rowSign == 0){
			for (int j = 1; j < colLen; j++){
				matrix[i][j] = 0;
			}
		}
		if (colSign == 0){
			for (int j = 1; j < rowLen; j++){
				matrix[j][i] = 0;
			}
		}
	}
	if (rFirst == 0){
		for (int j = 0; j < colLen; j++){
			matrix[0][j] = 0;
		}
	}
	if (cFirst == 0){
		for (int j = 0; j < rowLen; j++){
			matrix[j][0] = 0;
		}
	}
}