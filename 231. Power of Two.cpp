//由于2的n次方的二进制表示只有一个1，而n-1的二进制表示跟n的二进制位数全部不同，所以做&操作，若全部为0，则为真，否则为假
bool isPowerOfTwo(int n) {
    if(n<1)
        return false;
    int m=n&(n-1);
    return m==0;
}
