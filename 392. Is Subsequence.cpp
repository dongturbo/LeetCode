bool isSubsequence(string s, string t) {
    int i1=0,i2=0;
    //两个同时循环，循环一遍即可解决
    while(i1<s.length() && i2<t.length()){
        if(s[i1]==t[i2]){
            i1++;
            i2++;
        }else
            i2++;
    }
    if(i1==s.length())
        return true;
    else
        return false;
}
