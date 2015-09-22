int lengthOfLongestSubstring(string s) {
    int length = 0;
	int i = 0, j = 0;
	for (; j < s.size(); j++){
		for (int k=i; k < j; k++){
			if (s[k] == s[j]){

				if (j - i > length){
					length = j - i;
				}
				i = k + 1;
				break;
			}
		}

	}
	if (j - i > length){
		length = j - i;
	}
	return length;
    }