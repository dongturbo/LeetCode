/*解题思路：
	利用回溯法递归遍历,
	1.循环遍历每个元素，如果该元素和word中对应的元素相等，则递归遍历
	2.递归遍历时，判断这个元素相邻的四个元素是否已经被遍历过，没有的话，判断是否相等
	3.相等的话，递归遍历相邻的那个元素，不相等的话，遍历下一个相邻的元素
	4.若四个元素都不相等，则返回false，直到把word中的元素都遍历完则返回true
*/
bool recurExist(vector<vector<char>>& board, string word, int * mark,int row,int col,int nth){
	if (nth == word.size())
		return true;
	if (row > 0 && mark[(row - 1)*board[0].size() + col] == 0){
		mark[(row - 1)*board[0].size() + col] = 1;
		if (board[row - 1][col] == word[nth]){
			if (recurExist(board, word, mark, row - 1, col, nth + 1))
				return true;
		}
		mark[(row - 1)*board[0].size() + col] = 0;
	}
	if (col > 0 && mark[row*board[0].size() + col-1] == 0){
		mark[row*board[0].size() + col - 1] = 1;
		if (board[row][col - 1] == word[nth ]){
			if (recurExist(board, word, mark, row, col - 1, nth + 1))
				return true;
		}
		mark[row*board[0].size() + col - 1] = 0;
	}
	if (row+1 < board.size() && mark[(row + 1)*board[0].size() + col] == 0){
		mark[(row + 1)*board[0].size() + col] = 1;
		if (board[row + 1][col] == word[nth ]){
			if (recurExist(board, word, mark, row + 1, col, nth + 1))
				return true;
		}
		mark[(row + 1)*board[0].size() + col] = 0;
	}
	if (col + 1 < board[0].size() && mark[row*board[0].size() + col+1] == 0){
		mark[row*board[0].size() + col + 1] = 1;
		if (board[row][col+1] == word[nth]){
			if (recurExist(board, word, mark, row, col + 1, nth + 1))
				return true;
		}
		mark[row*board[0].size() + col + 1] = 0;
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	int rowLen = board.size();
	if (rowLen == 0)
		return false;
	int colLen = board[0].size();
	int *mark = new int[rowLen*colLen];
	memset(mark,0,rowLen*colLen*sizeof(int));
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			mark[i*colLen + j] = 1;
			if (board[i][j]==word[0])
				if(recurExist(board,word,mark,i,j,1))
					return true;
			mark[i*colLen + j] = 0;
		}
	}
	return false;
}