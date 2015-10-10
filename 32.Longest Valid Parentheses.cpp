 /*
第一种解法：
 	1.设置了bool的数组与s等长保存s中的匹配状态，利用栈来判断左右括号是否匹配，如果匹配则把bool数组中相同下标位置true。
	2.第一步循环完后，然后循环一遍bool数组统计出数组中连续为true的最大个数即为结果。
 */
 
int longestValidParentheses(string s) {
	bool *a = new bool[s.length()];
	memset(a, false, s.length());
	stack<int> st;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')' && !st.empty()) {
			a[i] = true;
			a[st.top()] = true;
			st.pop();
		}
	}
	int max_len = 0, cur_len = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (a[i]) ++cur_len;
		else cur_len = 0;
		max_len = max(max_len, cur_len);
	}
	return max_len;
}
	
/*
第二种解法(参考别人的)：
	一维动态规划逆向求解。假设输入括号表达式为String s，维护一个长度为s.length的一维数组dp[]，数组元素初始化为0。
	 dp[i]表示从s[i]到s[s.length - 1] 包含s[i] 的最长的有效匹配括号子串长度。
*/
	
int longestValidParentheses(string s) {	
	int len = s.length();
	int result = 0;
	const char *str = s.c_str();
	int *dp = new int[len];
	//把辅助数组清空，存储为0
	memset(dp, 0, len*sizeof(int));
	for (int i = len - 2; i >= 0; i--)
	{
		if (str[i] == '(')//只对左括号处理，右括号在数组中存储为0
		{
			int j = i + 1 + dp[i + 1];//计算与当前左括号匹配的右括号的位置。可能存在也可能不存在
			if (j<len && str[j] == ')')//确保位置不能越界
			{
				dp[i] = dp[i + 1] + 2;//找到了相匹配的右括号，当前数组中存储的最长长度是它后一个位置加2，后一个位置可能存储长度是0
				if (j + 1<len)//这是连接两个子匹配的关键步骤
					dp[i] += dp[j + 1];//在j的后面可能已经存在连续的匹配，要记得加上。dp[j+1]存储了以j+1开始的匹配
			}
			//更新最长长度
			result = max(result, dp[i]);
		}

	}
	return result;
}