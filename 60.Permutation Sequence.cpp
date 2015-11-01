/*解题思路：
	因为n个数有n!个序列，当第一位固定时，剩下的有(n-1)!个阶乘个排序，因此可以利用k/(n-1)!来确定第一位来安排某个数，然后k=k%(n-1)来确定第二位排某个数。依次类推，排出所有数。
	1.求出1-n的阶乘存到fac中，1-9存到nums中。
	2.k/fac[i-1]求出第n-i位需要安排的数。
	3.拼接result，以及k=%fac[i-1]，此时的k表示当第一位固定后，所要求的结果为剩下的序列的第k个。
	4.重复2、3步直到安排出最后一位数。
*/
string getPermutation(int n, int k) {
	vector<int> fac(n,1);
	vector<char> nums;
	vector<char>::iterator it;
	string result="";
	for (int i = 0; i < n; i++){
		nums.push_back(i + 1+'0');
		if (i>0)
			fac[i] =fac[i-1]* (i + 1);
	}
	k--;
	for (int i = n-1; i>0;i--){
		it = nums.begin() + k / fac[i-1];
		k = k%fac[i - 1];
		result += *it;
		nums.erase(it);
	}
	result += nums[0];
	return result;
}