/*动态规划问题,第一问很简单，每次到达当前格路径数为到达左边格路径数加上到达上边格的路径数
v[i][j]=v[i][j-1] + v[i-1][j],也可以利用上一轮的计算结果把二维空间下降为一维数组。
*/
int uniquePaths(int m, int n) {
	vector<int> v(n, 1);
	for (int i = 1; i<m; ++i){
		for (int j = 1; j<n; ++j){
			v[j] += v[j - 1];
		}
	}
	return v[n - 1];
}
