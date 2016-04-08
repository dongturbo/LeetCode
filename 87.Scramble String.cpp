/*解题思路:
    利用递归实现，根据题目要求，若s1和s2是isScramble，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，同样有s21和s22。可分为以下两种情况
    1.s11和s21是isScramble,同时s12和s22是isScramble
    2.s11和s22是isScramble,同时s12和s21是isScramble
    算法复杂度比较高，需进行剪枝才能通过
*/

bool isScramble(string s1, string s2) {
	 int len1 = s1.length();
	 int len2 = s2.length();
	 if (len1 != len2)
		 return false;
	 if (len1 == 1)
		 return s1 == s2;
	 string st1 = s1, st2 = s2;
	 sort(st1.begin(), st1.end());
	 sort(st2.begin(), st2.end());
	 for (int i = 0; i < len1; ++i) {
		 if (st1[i] != st2[i]) {
			 return false;
		 }
	 }
	 bool match = false;
	 string s11, s12, s21, s22;
	 for (int i = 1; i < len1 && !match; i++){
		 s11 = s1.substr(0, i);
		 s12 = s1.substr(i, len1 - i);
		 s21 = s2.substr(0, i);
		 s22 = s2.substr(i, len1 - i);
		 match = isScramble(s11, s21) && isScramble(s12, s22);
		 if (!match){
			 s21 = s2.substr(0, len1 - i);
			 s22 = s2.substr(len1 - i, i);
			 match = isScramble(s11, s22) && isScramble(s12, s21);
		 }

	 }
	 return match;
 }
 /*动态规划，参考网上答案：
 这其实是一道三维动态规划的题目，我们提出维护量res[i][j][n]，其中i是s1的起始字符，j是s2的起始字符，而n是当前的字符串长度，res[i][j][len]表示的是以i和j分别为s1和s2起点的长度为len的字符串是不是互为scramble。
有了维护量我们接下来看看递推式，也就是怎么根据历史信息来得到res[i][j][len]。判断这个是不是满足，其实我们首先是把当前s1[i...i+len-1]字符串劈一刀分成两部分，然后分两种情况：第一种是左边和s2[j...j+len-1]左边部分是不是scramble，以及右边和s2[j...j+len-1]右边部分是不是scramble；第二种情况是左边和s2[j...j+len-1]右边部分是不是scramble，以及右边和s2[j...j+len-1]左边部分是不是scramble。如果以上两种情况有一种成立，说明s1[i...i+len-1]和s2[j...j+len-1]是scramble的。而对于判断这些左右部分是不是scramble我们是有历史信息的，因为长度小于n的所有情况我们都在前面求解过了（也就是长度是最外层循环）。
上面说的是劈一刀的情况，对于s1[i...i+len-1]我们有len-1种劈法，在这些劈法中只要有一种成立，那么两个串就是scramble的。
总结起来递推式是res[i][j][len] = || (res[i][j][k]&&res[i+k][j+k][len-k] || res[i][j+len-k][k]&&res[i+k][j][len-k]) 对于所有1<=k<len，也就是对于所有len-1种劈法的结果求或运算。因为信息都是计算过的，对于每种劈法只需要常量操作即可完成，因此求解递推式是需要O(len)（因为len-1种劈法）。
如此总时间复杂度因为是三维动态规划，需要三层循环，加上每一步需要线行时间求解递推式，所以是O(n^4)。虽然已经比较高了，但是至少不是指数量级的，动态规划还是有很大有事的，空间复杂度是O(n^3)。代码如下：
 */
 
 
 bool isScramble(string s1, string s2) {
	 int len1 = s1.length();
	 int len2 = s2.length();
	 if (len1 != len2)
		 return false;
	 if (len1 == 1)
		 return s1 == s2;
	 bool ***match = new bool**[len1];
	 for (int i = 0; i < len1; i++){
		 bool **temp = new bool*[len1];
		 for (int j = 0; j < len1; j++){
			 temp[j] = new bool[len1];
		 }
		 match[i] = temp;
	 }
	 for (int i = 0; i < len1; i++){
		 for (int j = 0; j < len1; j++){
			 match[0][i][j] = s1[i] == s2[j];
		 }
	 }
	 for (int k = 2; k <= len1; ++k){
		 for (int i = len1 - k; i >= 0; --i){
			 for (int j = len1 - k; j >= 0; --j){
				 bool r = false;
				 for (int m = 1; m<k && !r; ++m){
					 r = (match[m - 1][i][j] && match[k - m - 1][i + m][j + m]) || (match[m - 1][i][j + k - m] && match[k - m - 1][i + m][j]);
				 }
				 match[k - 1][i][j] = r;
			 }
		 }
	 }
	 
	 return match[len1 - 1][0][0];
 }