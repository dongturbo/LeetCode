//分别按行、列、块检测，出现重复即返回false，没有的话最后返回true
bool isValidSudoku(vector<vector<char>>& board) {
	vector<int> cMark(9, 0),rMark(9,0),bMark(9,0);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			char rChar = board[i][j];
			char cChar = board[j][i];
			char bChar = board[(j / 3) + i / 3 * 3][(i % 3) * 3 + j % 3];
			//按行检测
			if (rChar != '.'){
				if (rMark[rChar - '1'] > 0) {
					return false;
				}
				else {
					++rMark[rChar - '1'];
				}
			}
			//按列检测
			if (cChar != '.'){
				if (cMark[cChar - '1'] > 0) {
					return false;
				}
				else {
					++cMark[cChar - '1'];
				}
			}
			//按块检测
			if (bChar != '.'){
				if (bMark[bChar - '1'] > 0) {
					return false;
				}
				else {
					++bMark[bChar - '1'];
				}
			}
		}
		rMark.assign(9, 0);
		cMark.assign(9, 0);
		bMark.assign(9, 0);
	}
	return true;
}