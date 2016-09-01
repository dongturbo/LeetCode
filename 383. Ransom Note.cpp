//用数组保存magazine字符串中字符出现的次数，由于字符可以用ascii码表示，所以128个字符足够。
bool canConstruct(string ransomNote, string magazine) {
    int map[128]={0};
    for(int i=0;i<magazine.size();i++){
        map[magazine[i]]++;
    }
    for(int i=0;i<ransomNote.size();i++){
        if(map[ransomNote[i]]<=0)
            return false;
        map[ransomNote[i]]--;
    }
    return true;
}
