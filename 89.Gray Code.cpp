/*解题思路：
    由题意可知graycode的属性，0,1,3,2；可从中找出规律，当n为1时，为{0,1}，当n为2时为{0,1,3,2}即把2依次倒着加上n为1的结果。
    由此可知n为3时，即2的2次方，依次倒序加上n为2的结果，由此递推得出n为n的结果。
*/
vector<int> grayCode(int n) {
	vector<int> result = {0};
	int base = 1;
	for (int i = 1; i <= n; i++){		
		for (int j = result.size()-1; j >=0; j--){
			result.push_back(base+result[j]);
		}
		base *= 2;
	}
	return result;
}
