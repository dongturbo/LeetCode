/*第一种方法，递归实现，但是大数据时会超时
*/
int numDecodings(string s) {
	if (s.length() == 0)
		return 0;
	if (s.length()== 1 )
		return 1;
	if ( 2 == s.length()){
		if (s[0] > '2' || s[0] == '2' && s[ 1] > '6')
			return 1;
		else
			return 2;
	}
	if (s[0] > '2' || s[0] == '2' && s[ 1] > '6'){
		return numDecodings(s.substr(1));
	}
	else
		return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
}
/*第二种方法，从最后开始往前计算，把计算的结果存储到数组中，相当于把递归每层的结果存到数组，通过数组的累加实现计算
*/
int numDecodings(string s) {
	if (s.length() == 0)
		return 0;
	vector<int> result(s.length()+2,1);
	for (int i = s.length()-1; i >=0; i--){
		if (s[i] == '0')
			result[i] = 0;
		else
			result[i] = result[i + 1];
		if (i + 1 < s.length() && ((s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))))
			result[i] += result[i + 2];
	}
	return result[0];
}