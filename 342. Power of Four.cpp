//根据2的次方的原理，以及4的次方肯定能被开方成整数，可用以下方式判断
bool isPowerOfFour(int n) {
    if(n<1) return false;
    int root = (int)sqrt(n);
    return (n&(n-1))==0 && n-root*root==0;
}
