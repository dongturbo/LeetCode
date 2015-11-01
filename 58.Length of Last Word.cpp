//这道题比较简单，从最后往前数就行了
int lengthOfLastWord(string s) {
	int length = s.size(),count=0;
	for (int i = length-1; i >=0; i--){
		if (s[i] != ' ')
			count++;
		else{			
			if (count != 0)
				break;
		}			
	}
	return count;
}
