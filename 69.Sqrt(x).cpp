/*解题思路：
	通过t的递增并判断t的平方是否是最接近x且小于x的那个值，如果单纯的每次递增1的话这样会超时，所以这里是按指数递增，以最快递增到想要的那个结果。
*/
int mySqrt(int x) {
	long long t = 0,s=x;
	while (true){
		int k = 1,l=1;
		while (t*t <= s){
			t += k;
			l = k;
			k *= 2;
		}
		if ((t - 1)*(t - 1) <= s){
			return t - 1;
		}
		t -= l;
	}
}