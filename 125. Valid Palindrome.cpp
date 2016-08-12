//直接在原字符串判断
bool isPalindrome(string s) {
    int begin=0,end=s.length()-1;
    while(begin<=end){
        if(!(s[begin]>='0' && s[begin]<='9' || s[begin]>='a' && s[begin]<='z' || s[begin]>='A' && s[begin]<='Z')){
            begin++;
            continue;
        }
        if(!(s[end]>='0' && s[end]<='9' || s[end]>='a' && s[end]<='z' || s[end]>='A' && s[end]<='Z')){
            end--;
            continue;
        }
        if(s[begin]>='A' && s[begin]<='Z')
            s[begin]+=32;
        if(s[end]>='A' && s[end]<='Z')
            s[end]+=32;
        if(s[begin++]!=s[end--])
            return false;
    }
    return true;
}
//拷贝到新字符串去判断
bool isPalindrome(string s) {
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z'){
            temp+=s[i];
        }else if(s[i]>='A' && s[i]<='Z')
            temp+=(s[i]+32);
    }
    int length=temp.length();
    for(int i=0;i<length/2;i++){
        if(temp[i]!=temp[length-i-1])
            return false;
    }
    return true;
}
