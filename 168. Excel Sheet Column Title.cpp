string convertToTitle(int n) {
    string s = "";
	char c;
	while (n >0){
		if (n == 26){
			c = 'Z';
			s = c + s;
			break;
		}
		if (n % 26 == 0){
			c = 'Z';
			n--;
		}
		else{
			c = (n % 26 - 1) + 'A';
		}
		s = c + s;
		n /= 26;
	}
	return s;
}
