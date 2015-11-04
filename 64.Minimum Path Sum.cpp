//和上一题类似，只是paths[i]=grid[i][j]+min(paths[j], paths[j - 1]);
//即当前路径等于上面元素的路径长度和左边路径长度中较小的那个与当前元素的和。
int minPathSum(vector<vector<int>>& grid) {
	int rowLen = grid.size();
	int colLen = grid[0].size();
	vector<int> paths(colLen,INT_MAX);
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			if (j == 0){
				if (i == 0){
					paths[j] = grid[i][j];
					continue;
				}
				paths[j] = paths[j] + grid[i][j];					
			}
			else{
				paths[j] = min(paths[j], paths[j - 1]) + grid[i][j];
			}
		}
	}
	return paths[colLen-1];
}