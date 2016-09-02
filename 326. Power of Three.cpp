//求以3为底的对数，如果求出来的结果是个整数的话，则为真，否则为假
bool isPowerOfThree(int n) {
   if(n == 0) return false;
    double x = log10(n) / log10(3);
    return floor(x) == x;
}
