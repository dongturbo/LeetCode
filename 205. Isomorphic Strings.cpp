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
