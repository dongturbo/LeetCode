/*首先计算nums数组中所有数字的异或，记为xor

令lowbit = xor & -xor，lowbit的含义为xor从低位向高位，第一个非0位所对应的数字

例如假设xor = 6（二进制：0110），则-xor为（二进制：1010，-6的补码，two's complement）

则lowbit = 2（二进制：0010）

根据异或运算的性质，“同0异1”

记只出现一次的两个数字分别为a与b

可知a & lowbit与b & lowbit的结果一定不同

通过这种方式，即可将a与b拆分开来
*/

vector<int> singleNumber(vector<int>& nums) {
	int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	diff &= -diff;
	vector<int> res(2, 0);
	for (auto &a : nums) {
		if (a & diff) 
			res[0] ^= a;
		else 
			res[1] ^= a;
	}
	return res;

}
