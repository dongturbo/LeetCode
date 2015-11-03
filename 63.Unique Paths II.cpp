//和上题类似，只是加了一个判断过程，如果obstacleGrid[i][j]为0的话，paths[j]=paths[j] + paths[j - 1]，否则为0；
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int rowLen = obstacleGrid.size();
	if (rowLen == 0)
		return 0;
	int colLen = obstacleGrid[0].size();
	vector<int> paths(colLen);
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			if (j == 0){
				if (i == 0){
					paths[j] = obstacleGrid[i][j] == 0 ? 1 : 0;
					continue;
				}
				paths[j] = obstacleGrid[i][j] == 0 ? paths[j] : 0;
				
			}
			else{
				paths[j] = obstacleGrid[i][j] == 0 ? paths[j] + paths[j - 1] : 0;
			}
		}
	}
	return paths[colLen - 1];
}
