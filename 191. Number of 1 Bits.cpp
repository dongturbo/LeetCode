//由于n有32位，因此循环32次，每次与1做与操作，结果为1则累加
int hammingWeight(uint32_t n) {
    int count=0;
    for(int i=0;i<32;i++){
        count+=n&1;
        n>>=1;
    }
    return count;
}
