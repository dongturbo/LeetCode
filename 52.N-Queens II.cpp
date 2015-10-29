//解题思路参考上一题
void fillQueens(int n, int place, int xAxis[],int yAxis[], int& count){
	if (place == n){
		count++;
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
				fillQueens(n, place + 1, xAxis, yAxis, count);
				yAxis[i] = 0;
			}
		}		
	}	
	return;
	
}

int totalNQueens(int n) {
	int count = 0;
	int * xAxis = new int[n];
	int * yAxis = new int[n];
	memset(yAxis, 0, n*sizeof(int));
	fillQueens(n, 0, xAxis, yAxis, count);
	return count;
}