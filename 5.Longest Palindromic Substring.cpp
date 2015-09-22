string longestPalindrome(string str) {
    	int longest = 0,start=0;
	const char *s = str.c_str();
	int length = str.size();
	if (length == 1){
		return s;
	}

	for (int i = 0, j = length - 1; j > i; j--){
		for (int m = 0; m < length - (j - i); m++){
				bool check = true;
				for (int k = 0; k < (j - i) / 2 + 1; k++){
					if (s[i +m+ k] != s[j +m- k]){
						check = false;
						break;
					}
				}
				if (check){
					longest = j - i + 1;
					start = i+m;
					return str.substr(start, longest);
				}
			}			
		}
}