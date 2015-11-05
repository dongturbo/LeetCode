//这道题比较简单，其实就是对加法和进位的处理
string addBinary(string a, string b) {
	int len1 = a.size();
	int len2 = b.size();
	int i = len1 - 1, j = len2 - 1, carry = 0;
	string result;
	while (i >= 0 || j >= 0 || carry>0){
		if (i >= 0 && j >= 0){
			int sum = (a[i] + b[j] + carry - '0' - '0');
			char t = sum % 2 + '0';
			result = t + result;
			carry = sum / 2;
			i--; j--;
		}
		else if (i >= 0){
			while (i >= 0){
				int sum = (a[i] + carry - '0');
				char t = sum % 2 + '0';
				result = t + result;
				carry = sum / 2;
				i--;
			}		
		}
		else if (j >= 0){
			while (j >= 0){
				int sum = (b[j] + carry - '0');
				char t = sum % 2 + '0';
				result = t + result;
				carry = sum / 2;
				j--;
			}		
		}
		else if (carry>0){
			char t = carry + '0';
			result = t + result;
			break;
		}
	}
	return result;
}
