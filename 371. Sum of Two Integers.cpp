int getSum(int a, int b) {
    while(b)
    {
        int c = a^b;
        int d = (a&b)<<1;
        a = c;
        b = d;
    }
    return a;
}
