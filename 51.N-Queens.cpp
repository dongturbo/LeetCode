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

//添加了一个记录Y轴的标记位，减少了时间复杂度
void fillQueens(int n, int place, int xAxis[],int yAxis[], vector<vector<string>>& result){
	if (place == n){
		vector<string> temp;
		for (int i = 0; i < place; i++){
			string str(n, '.');
			str[xAxis[i]] = 'Q';
			temp.push_back(str);			
		}
		result.push_back(temp);
		return;
	}
	for (int i = 0; i < n; i++){
		if (yAxis[i] == 0){
			int j = 0;
			for (; j < place; j++){
				if (abs(place - j) == abs(i - xAxis[j])){
					break;
				}
			}
			if (j==place){
				xAxis[place] = i;
				yAxis[i] = 1;
				fillQueens(n, place + 1, xAxis,yAxis, result);
				yAxis[i] = 0;
			}
		}		
	}	
	return;
	
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> result;
	int * xAxis= new int[n];
	int * yAxis = new int[n];
	memset(yAxis,0,n*sizeof(int));
	fillQueens(n, 0, xAxis, yAxis, result);
	return result;
}