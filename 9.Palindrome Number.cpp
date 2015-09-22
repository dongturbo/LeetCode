bool isPalindrome(int x) {
        	long long result = 0;
	
	int temp = x;
	while (x>0){
		result = 10 * result + x % 10;
		x = x / 10;
	}
	return result == temp;
    }