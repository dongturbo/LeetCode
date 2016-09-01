//理解题意后不难发现，只要不是四的整数倍，剩余的余数就是你第一次要拿的个数，然后每次凑到四个就行
bool canWinNim(int n) {
    if(n%4==0)
        return false;
    return true;
}
