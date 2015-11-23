/*解题思路：
	1.判断target是否在矩阵某一行的范围内，在的话就用二分查找
	2.不在的话就循环到下一行
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int rowLen = matrix.size();
	if (rowLen == 0 || matrix[0].size()==0)
		return false;
	int colLen = matrix[0].size();
	for (int i = 0; i < rowLen; i++){		
		if (target >= matrix[i][0] && target <= matrix[i][colLen - 1]){
			int low = 0, high = colLen - 1;
			while (low <= high){
				int mid = matrix[i][(low + high) / 2];
				if (target == mid)
					return true;
				if (target < mid)
					high = (low + high) / 2 - 1;
				else
					low = (low + high) / 2 + 1;
			}
			return false;
		}
		if (target < matrix[i][0])
			return false;
	}
	return false;
}