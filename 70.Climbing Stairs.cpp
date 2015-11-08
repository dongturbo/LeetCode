/*解题思路：
	利用DP的方法，一个台阶的方法次数为1次，两个台阶的方法次数为2个。
	n个台阶的方法可以理解成上n-2个台阶，然后2步直接上最后一步；或者上n-1个台阶，再单独上一步。
	公式是S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
*/
int climbStairs(int n) {
	if (n <= 2)
	{
		return n;
	}
	else
	{
		int* step = new int[n];
		step[0] = 1;
		step[1] = 2;
		for (int i = 2; i < n; i++)
		{
			step[i] = step[i - 1] + step[i - 2];
		}
		return step[n - 1];
	}
}