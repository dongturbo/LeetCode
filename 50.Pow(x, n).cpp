/*解题思路：
	如果直接循环的话会超时。因此得缩短循环次数，例如
	1. x*x后保存结果为temp，并记录成的次数，然后利用temp*temp
	2. 当次数超过n时，把次数除2，然后n=n-乘的次数，再执行步骤1。
	3. 直到n=0时停止
*/
double myPow(double x, int n) {
	if (n == 0)
		return 1;
	long long abs = n > 0 ? n : -n;
	double result = 1, temp = x; 
	long long i = 2;
	while (abs>0){
		while (i <= abs){
			temp = temp*temp;
			i *= 2;
		}
		result *= temp;
		abs = abs - i / 2;
		i = 2;
		temp = x;
	}
	return n>0?result:1/result;
}
