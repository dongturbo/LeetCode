/*解题思路:
	n皇后问题，主要利用回溯。每次取值时判断是否满足和前面的都不同行、同列、同斜线，如果满足则计算下一个，不满足则回溯到上一个重新赋值。
*/
void fillQueens(int n, int place, vector<int>& coords, vector<vector<string>>& result){	
	if (place == n){
		vector<string> temp(n, string(n, '.'));
		for (int i = 0; i < coords.size(); i++){
			temp[i][coords[i]] = 'Q';			
		}
		result.push_back(temp);
		return;
	}
	bool check;
	for (int i = 0; i < n; i++){
		check = true;
		for (int j = 0; j < coords.size(); j++){
			int y = coords[j];
			if (i == y || place - j == i - y || place- j == y - i){
				check = false;
				break;
			}
		}
		if (check){
			coords.push_back(i);
			fillQueens(n,place+1,coords,result);
			coords.pop_back();
		}
	}	
	return;
	
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> result;
	vector<int> coords;
	fillQueens(n, 0, coords, result);
	return result;
}