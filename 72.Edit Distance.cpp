/*利用动态规划
1）若word1[i+1]==word2[j+1] dp[i+1][j+1] = dp[i][j]；否则，dp[i+1][j+1] = dp[i][j] + 1。（利用替换原则）
2）dp[i+1][j+1]还可以取dp[i][j+1]与dp[i+1][j]中的较小值。（利用删除添加原则）
*/
int min(int a,int b,int c){
	if (a > b){
		a = b;
	}
	if (a > c){
		a = c;
	}
	return a;
}
int minDistance(string word1, string word2) {
	int l1 = word1.size(), l2 = word2.size();
	if (l1 == 0 || l2 == 0){
		if (l1 != 0)
			return l1;
		if (l2 != 0)
			return l2;
		return 0;
	}
	vector<vector<int>> matrix(l1+1,vector<int>(l2+1));
	for (int i = 0; i < l1 + 1; i++)
		matrix[i][0] = i ;
	for (int i = 0; i < l2 + 1; i++)
		matrix[0][i] = i ;
	for (int i = 1; i < l1+1; i++){
		for (int j = 1; j < l2+1; j++){
			int subs = word1[i-1] == word2[j-1] ? 0 : 1;
			matrix[i][j] = min(matrix[i - 1][j - 1] + subs, matrix[i - 1][j] + 1, matrix[i][j - 1] + 1);
		}
	}
	return matrix[l1][l2];
}
