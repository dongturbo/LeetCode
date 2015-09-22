//'*'必须结合前面的字符一块使用， "a*" 表示0个或多个a
// 利用递归来实现这种匹配

bool isMatch(string s, string p) {
	const char * str1 = s.c_str();
	const char * str2 = p.c_str();
	if (*str2 == '\0'){
		return *str1 == '\0';
	}
	if (*(str2 + 1) != '*'){
		if (*str1 != '\0' && (*str1 == *str2 || *str2 == '.'))
			return isMatch(str1 + 1, str2 + 1);
		else
			return false;
	}
	else{
		while (*str1 != '\0' && (*str1 == *str2 || *str2 == '.')){
			if (isMatch(str1, str2 + 2))
				return true;
			str1++;
		}
		return isMatch(str1, str2 + 2);
	}
}