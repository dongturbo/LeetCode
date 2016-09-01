//可以利用char的ascii码来做异或运算，不同的那个字符肯定出现的奇数次，因此对所有异或，最终剩的便是那个字符
char findTheDifference(string s, string t) {
    if(s.empty())
        return t[0];
    int ch=(int)s[0];
    for(int i=1;i<s.length();i++){
        ch^=(int)s[i];
    }
    for(int i=0;i<t.length();i++){
        ch^=(int)t[i];
    }
    return (char)ch;
}
