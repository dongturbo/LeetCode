//用数组做map记录每个字符出现的次数
int firstUniqChar(string s) {
    int map[128]={0};
    for(int i=0;i<s.length();i++){
        map[s[i]]++;
    }
    for(int i=0;i<s.length();i++){
        if(map[s[i]]==1)
            return i;
    }
    return -1;
}
