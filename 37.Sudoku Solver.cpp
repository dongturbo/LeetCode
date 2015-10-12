/*这里解数读的时候用到了两种方法：
	1.用到了唯一法，即首先找到所有能够唯一确定的位置，有些数独利用此种方法即可解决，有些数独的一下空位是没法唯一确定
	2.无法唯一确定的只能去试探，所以得用到回溯，如果接下来填写的数字无法达到合法状态，即往上回溯，直到成功。
*/
class Solution {
public:
    int rowValid[9][10];//rowValid[i][j]表示第i行数字j是否已经使用
    int columnValid[9][10];//columnValid[i][j]表示第i列数字j是否已经使用
    int subBoardValid[9][10];//subBoardValid[i][j]表示第i个小格子内数字j是否已经使用
    void fill(int row, int col, int val)
    {
    	rowValid[row][val] = 1;
    	columnValid[col][val] = 1;
    	subBoardValid[row / 3 * 3 + col / 3][val] = 1;
    }
    bool fillSudoku(vector<vector<char>>& board, int row, int col) {
    	vector<int> mark(9, 0);
    	int count = 0;
    	for (int i = 0; i < 9; i++){
    		char rChar = board[row][i];
    		char cChar = board[i][col];
    		char bChar = board[(i / 3) + row / 3 * 3][(col / 3) * 3 + i % 3];
    		//cout << (i / 3) + row / 3 * 3 << " " << (col / 3) * 3 + i % 3 << endl;
    		if (rChar != '.'){
    			count = mark[rChar - '1'] == 0 ? count+1 : count;
    			++mark[rChar - '1'];
    		}
    		if (cChar != '.'){
    			count = mark[cChar - '1'] == 0 ? count+1 : count;
    			++mark[cChar - '1'];
    		}
    		if (bChar != '.'){
    			count = mark[bChar - '1'] == 0 ? count+1 : count;
    			++mark[bChar - '1'];
    		}
    	}
    	if(count==8){
    		for (int i = 0; i < 9; i++){
    			if (mark[i] == 0){
    				board[row][col] = i+'1';
    				//cout << row << " " << col << " " << i +1 << endl;
    			}
    		}
    		return true;
    	}
    	return false;
    }
    //清除填充状态
    void clear(int row, int col, int val)
    {
    	rowValid[row][val] = 0;
    	columnValid[col][val] = 0;
    	subBoardValid[row / 3 * 3 + col / 3][val] = 0;
    }
    //判断在第row行col列填充数字val后，是否是合法的状态
    bool isValid(int row, int col, int val)
    {
    	if (rowValid[row][val] == 0 &&
    		columnValid[col][val] == 0 &&
    		subBoardValid[row / 3 * 3 + col / 3][val] == 0)
    		return true;
    	return false;
    }
    
    bool solver(vector<vector<char> > &board, int index)
    {// 0 <= index <= 80，index表示接下来要填充第index个格子
    	if (index > 80)return true;
    	int row = index / 9, col = index - 9 * row;
    	if (board[row][col] != '.')
    		return solver(board, index + 1);
    	for (int val = '1'; val <= '9'; val++)//每个为填充的格子有9种可能的填充数字
    	{
    		if (isValid(row, col, val - '0'))
    		{
    			board[row][col] = val;
    			fill(row, col, val - '0');
    			if (solver(board, index + 1))return true;
    			clear(row, col, val - '0');
    		}
    	}
    	board[row][col] = '.';//注意别忘了恢复board状态
    	return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool check = false, finish = true;
    	do{
    		check = true; finish = true;
    		for (int i = 0; i < 9; i++){
    			for (int j = 0; j < 9; j++){
    				if (board[i][j] == '.'){
    					check=fillSudoku(board, i, j)?false:check;
    					finish = false;
    				}					
    			}
    		}
    	}while (!check);
    	//cout << (finish ? "true" : "false") << endl;
    	if (!finish){
    		for (int i = 0; i < 9; i++)
    			for (int j = 0; j < 9; j++)
    				if (board[i][j] != '.')
    					fill(i, j, board[i][j] - '0');
    		solver(board, 0);
    	}
    }
};