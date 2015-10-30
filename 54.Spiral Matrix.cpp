/*解题思路：
	螺旋展示，即先展示上边、其次右边、然后下边，最后左边。主要就是判断是否展示完毕比较麻烦。
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	int rowLength = matrix.size(), rowMid = (rowLength+1)/ 2;
	if (rowLength == 0)
		return result;
	int colLength = matrix[0].size(), colMid = (colLength+1)/ 2;
	int i = 0, k = 0;
	while (k < colMid || i < rowMid){
		if (i < rowMid){
			for (int j = i; j < colLength - i; j++){
				result.push_back(matrix[i][j]);	
			}
		}
		if (k < colMid){
			for (int l = k; l < rowLength - k - 2; l++){
				result.push_back(matrix[l + 1][colLength - k - 1]);
			}
		}
		if (i < rowLength-rowMid){
			for (int j = i; j < colLength - i; j++){
				result.push_back( matrix[rowLength - i - 1][colLength - j - 1]);
			}

		}		
		if (k < colLength-colMid){
			for (int l = k; l < rowLength - k - 2; l++){
				result.push_back(matrix[rowLength - l - 2][k]);
			}

		}
		i++;
		k++;
	}
	return result;
}

//这种方法是针对nxn矩阵的，不符合题意。
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	int length = matrix.size(), mid = length / 2,lastSpace=0;
	for (int i = 0; i < mid; i++){
		int len = length - i - i - 1;
		result.resize(lastSpace + 4 * len);
		for (int j = i; j < length - i-1; j++){
			result[lastSpace+j-i] = matrix[i][j];
			result[lastSpace + j-i + len] = matrix[j][length - i - 1];
			result[lastSpace + j -i+ 2 * len] = matrix[length - i - 1][length - j - 1];
			result[lastSpace + j -i+ 3 * len] = matrix[length - j - 1][i];
		}
		lastSpace = 4 * len;
	}
	if (length % 2 == 1){
		result.push_back(matrix[mid][mid]);
	}
	return result;
}
