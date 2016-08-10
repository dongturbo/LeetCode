//动态规划+滚动数组，找去其中的关系式，f(x,y)表示到x层y个元素的最小路径和，那个可得f(x,y)=min(f(x-1,y),f(x-1,y-1))+triangle[x][y]
int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> minSum(triangle.size(), 0);
	int length = triangle.size();
	for (int i = 0; i<triangle.size(); i++){
		for (int j = 0; j<i + 1; j++){
			if (j == 0 && i!=0){;
				minSum[length + j - i - 1] = minSum[length + j - i]+triangle[i][j];
			}
			else if (j == i){
				minSum[length + j - i - 1] += triangle[i][i];
			}
			else{
				minSum[length + j - i - 1] = min(minSum[length + j - i], minSum[length + j - i - 1]) + triangle[i][j];
			}
		}
	}
	int minTotal = minSum[0];
	for (int i = 1; i<triangle.size(); i++)
		minTotal = min(minTotal, minSum[i]);
	return minTotal;
}
//自底向上，这样最上面那个元素即为最小路径
int minimumTotal (vector<vector<int>>& triangle) {
	for (int i = triangle.size() - 2; i >= 0; --i)
	    for (int j = 0; j < i + 1; ++j)
	        triangle[i][j] += min(triangle[i + 1][j],
	        triangle[i + 1][j + 1]);
	return triangle [0][0];
}
