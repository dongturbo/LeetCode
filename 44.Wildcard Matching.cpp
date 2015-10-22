/*
如果用递归的话会超时，正确的做法是贪心算法
我们来匹配s和p，如果匹配就s++ , p++，如果不匹配的话就看p之前是否有*
当然是否有*我们需要记录的,遇到*就记录当前*的位置和匹配到的s的位置
然后从*的下一位置匹配,开始匹配0个字符
如果ok往后走,往后不ok,那么匹配1个字符...同理2,3,4个字符(有点回溯的感觉吧
所以实践复杂度是O(len(s) * len(p))
*/
bool isMatch(string s, string p) {
	const char* star = nullptr, *sLast = nullptr;
	const char* str1 = s.c_str(), *str2 = p.c_str();
	while (*str1){
		if (*str1 == *str2 || *str2 == '?'){
			str1++; str2++;
			continue;
		}
		if (*str2 == '*'){
			star = str2;
			str2++;
			sLast = str1;
			continue;
		}
		if (star != nullptr){
			str2 = star + 1;
			str1 = sLast + 1;
			sLast++;
			continue;
		}
		return false;
	}
	while (*str2 == '*')
		str2++;
	return *str2 == '\0';
}