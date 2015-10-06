//由于不让用*、/、%，还可以用的有+、-、>>、<<，这里主要用的是>>、<<，分别表示向右移位和向左移位。
/*大体思路是：
	1.先把divisor向左移一位，判断是否大于dividend，小于的话一直循环移位，直到找到最接近dividend的值；然后dividend减去移位后的divisor，同时设一个count，做和divisor同样的移位。
	2.减后的值作为1.步中的dividend，重新执行1步，并对count进行累加。
	3.直到最后减后的值小于divisor截止，最后累加后的count即为结果。
*/
int divide(int dividend, int divisor) {
	if (divisor == 0)
		return 2147483647;
	if (divisor == 1){
		return dividend;
	}
	long long absDividend = (long long)dividend>0 ? dividend : -(long long)dividend, absDivisor = (long long)divisor>0 ? divisor : -(long long)divisor;
	long long temp, count, result = 0;
	while (absDividend >= absDivisor){
		temp = absDivisor;
		count = 1;
		while (temp <= absDividend){
			temp <<= 1;
			count <<= 1;
		}
		temp >>= 1;
		count >>= 1;
		absDividend -= temp;
		result += count;
	}
	if (result > 2147483647){
		return 2147483647;
	}
	return (dividend<0 && divisor<0 || dividend>0 && divisor>0) ? result : -result;
}