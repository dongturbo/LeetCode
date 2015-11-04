/*题目比较简单，求一个含有数字的数组加一后的结果
	即从最后一位开始加一，然后插入到数组中，数如果大于10的话求模，依次求到第一位即可。
*/
vector<int> plusOne(vector<int>& digits) {
	int length = digits.size(),carry=1;
	vector<int> result;
	vector<int>::iterator it = result.begin();
	for (int i = length-1; i >=0 ; i--, it = result.begin()){
		result.insert(it,(digits[i]+carry)%10);
		carry = (digits[i] + carry) / 10;
	}
	if (carry>0)
		result.insert(it,carry);
	return result;
}