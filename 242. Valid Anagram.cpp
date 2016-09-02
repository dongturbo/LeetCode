//利用数组存储每个单词出现的频率，然后遍历另一个字符串时，对每个单词的频次减1，最终如果频率都为0的话，表示true否则false
bool isAnagram(string s, string t) {
    int check[128]={0};
    for(int i=0;i<s.length();i++){
        check[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        check[t[i]]--;
    }
    for(int i=0;i<128;i++){
        if(check[i]!=0)
            return false;
    }
    return true;
}
