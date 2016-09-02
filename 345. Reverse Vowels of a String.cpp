//单遍循环，遇到元音就替换
string reverseVowels(string s) {
	int begin = 0, end = s.length() - 1;
	while (begin < end){
		while (begin < end && (s[begin] != 'a' && s[begin] != 'o' && s[begin] != 'e' && s[begin] != 'i' && s[begin] != 'u' && s[begin] != 'A' && s[begin] != 'O' && s[begin] != 'E' && s[begin] != 'I' && s[begin] != 'U'))
			begin++;
		while (begin <end && (s[end] != 'a' && s[end] != 'o' && s[end] != 'e' && s[end] != 'i' && s[end] != 'u' && s[end] != 'A' && s[end] != 'O' && s[end] != 'E' && s[end] != 'I' && s[end] != 'U'))
			end--;
		if (begin>=end)
			break;
		char t = s[begin];
		s[begin] = s[end];
		s[end] = t;
		begin++, end--;
	}
	return s;
}

//两遍循环，先把元音存储到数组中，第二遍循环时替换
string reverseVowels(string s) {
  	int begin = 0, end = s.length() - 1;
  	while (begin < end){
  		while (begin < end && (s[begin] != 'a' && s[begin] != 'o' && s[begin] != 'e' && s[begin] != 'i' && s[begin] != 'u' && s[begin] != 'A' && s[begin] != 'O' && s[begin] != 'E' && s[begin] != 'I' && s[begin] != 'U'))
  			begin++;
  		while (begin <end && (s[end] != 'a' && s[end] != 'o' && s[end] != 'e' && s[end] != 'i' && s[end] != 'u' && s[end] != 'A' && s[end] != 'O' && s[end] != 'E' && s[end] != 'I' && s[end] != 'U'))
  			end--;
  		if (begin>=end)
  			break;
  		char t = s[begin];
  		s[begin] = s[end];
  		s[end] = t;
  		begin++, end--;
  	}
  	return s;
  }
