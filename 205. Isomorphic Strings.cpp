/* 利用两个map对记录两个字符串的映射关系，并把t按照t,s的映射关系转换成r，若r和s相同则为真，否则为假
*/
bool isIsomorphic(string s, string t) {
    char mapS[128],mapT[128] ;
	memset(mapS, '0', 128 * sizeof(char));
	memset(mapT, '0', 128 * sizeof(char));
	string r = "";
	if (s.length() != t.length())
		return false;
	for (int i = 0; i<s.length(); i++){
		if (mapS[s[i]] == '0' && mapT[t[i]]=='0'){
			mapT[t[i]] = s[i];
			mapS[s[i]] = t[i];
			r += s[i];
		}
		//若s存在映射t不存在，或者t存在映射s不存在都为假
		else if(!(mapS[s[i]] != '0' && mapT[t[i]]!='0' )){
		    return false;
		}else{
			r += mapT[t[i]];
		}
	}
	for (int i = 0; i<s.length(); i++){
		if (s[i] != r[i])
			return false;
	}
	return true;
}
//第二种解法，参考别人的
bool isIsomorphic(string s, string t) {
    int cs[128] = {0}, ct[128] = {0};
    for(int i=0; i<s.size(); i++)
    {
        if(cs[s[i]] != ct[t[i]]) return false;
        else if(!cs[s[i]] && !ct[t[i]]) //only record once
        {
            cs[s[i]] = i+1;
            ct[t[i]] = i+1;
        }
    }
    return true;
}
