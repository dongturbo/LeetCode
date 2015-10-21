//第一种方法即把乘法转换成加法计算。
string add(string num1, string num2){
	int len1 = num1.size();
	int len2 = num2.size();
	int gap = 0;
	string str1, str2, result;
	if (len1 > len2){
		str1 = num1;
		str2 = num2;
		gap = len1 - len2;
	}
	else{
		str1 = num2;
		str2 = num1;
		gap = len2 - len1;
	}
	string temp = str1.substr(gap);
	int last = 0; char c;
	for (int i = temp.size()-1; i >= 0; i--){
		int sum = temp[i] + str2[i] + last - 96;
		c = sum % 10 +'0';
		result = c + result;
		last = sum / 10;
	}
	temp = str1.substr(0, gap);
	for (int i = gap - 1; i >= 0; i--){
		int sum = temp[i] - 48 + last;
		c = sum % 10 + '0';
		result = c + result;
		last = sum / 10;
	}
	if (last != 0){
		c= last + '0';
		result = c + result;
	}
	return result;
}
string multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	string multip1, multip2,result;
	if (len1 > len2){
		multip1 = num1; multip2 = num2;
	}
	else{
		multip1 = num2; multip2 = num1;
	}
	for (int i = 0; i < multip2.size(); i++){
		string temp = multip1;
		for (int j = 1; j < multip2.size()-i; j++){
			temp += '0';
		}
		for (int j = 0; j < multip2[i] - 48; j++){
			result = add(temp, result);
		}
	}
	return result!=""?result:"0";
}

//模拟乘法运算，即按照乘法公式，按位相乘，然后累加
string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";
	int l1 = num1.length(), l2 = num2.length();
	string result;
	int *ch1 = new int[l1];
	int *ch2 = new int[l2];
	int *temp = new int[l1 + l2];
	memset(temp, 0, sizeof(int)*(l1 + l2));
	for (int i = 0; i < l1; i++)
		ch1[i] = num1[i] - '0';
	for (int i = 0; i < l2; i++)
		ch2[i] = num2[i] - '0';
	for (int i = 0; i < l1; i++){
		for (int j = 0; j < l2; j++){
			temp[i + j] += ch1[i]*ch2[j];
		}
	}
	int last = 0;
	for (int i = l1 + l2-2; i >=0; i--){
		int sum = temp[i]+ last;
		char ch= sum % 10 + '0';
		result = ch + result;
		last = sum / 10;
	}
	if (last != 0){
		char ch = last + '0';
		result = ch + result;
	}
	return result;
}