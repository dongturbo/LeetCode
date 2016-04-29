/*三层循环判断，不过每层限制条件比较多，所以代码比较冗杂
*/
vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	string temp;
	int length = s.length();
	int l1 = length - 3 * 3;
	l1 = l1 > 0 ? l1 : 1;
	for (int i = l1;length- i >=3 && i<=3; i++){
		//判断是否合理
		if (i == 3){
			if (s[0] =='1' || s[0] == '2' && (s[1] < '5' || s[1] == '5' && s[2] <= '5'))
				temp += s.substr(0, i);
			else{
				temp = "";
				continue;
			}				
		}
		else{
			if (i == 2 && s[0] == '0')
			{
				temp = "";
				continue;
			}				
			temp += s.substr(0, i);
		}		
		int l2 = length - i - 2 * 3;
		l2 = l2 > 0 ? l2 : 1;
		for (int j = l2;length-i- j >=2 && j<=3; j++){
			temp += '.';
			//判断是否合理
			if (j == 3){
				if (s[i] =='1' || s[i] == '2' && (s[i+1] < '5' || s[i+1] == '5' && s[i+2] <= '5'))
					temp += s.substr(i, j);
				else{
					temp = temp.substr(0, i);
					continue;
				}					
			}
			else{
				if (j == 2 && s[i] == '0'){
					temp = temp.substr(0, i);
					continue;
				}
				temp += s.substr(i, j);
			}
			int l3 = length - i - j - 3;
			l3 = l3 > 0 ? l3 : 1;
			for (int k = l3;length-i-j-k>=1&& k<=3; k++){
				temp += '.';
				//判断是否合理
				if (k == 3){
					if (s[i+j] =='1' || s[i+j] == '2' && (s[i+j + 1] < '5' || s[i+j + 1] == '5' && s[i+j + 2] <= '5'))
						temp += s.substr(i+j, k);
					else{
						temp = temp.substr(0, i + j + 1);
						continue;
					}						
				}
				else{
					if (k == 2 && s[i + j] == '0'){
						temp = temp.substr(0, i + j + 1);
						continue;
					}						
					temp += s.substr(i+j, k);
				}
				temp+='.';
				if (length - i - j - k == 3){
					if (s[i + j + k] =='1' || s[i + j + k] == '2' && (s[i + j + k + 1] < '5' || s[i + j + k + 1] == '5' && s[i + j + k + 2] <= '5')){
						temp += s.substr(i + j + k);
						result.push_back(temp);
					}
				}
				else{
					if (length - i - j - k == 2 && s[i + j + k] == '0'){
						temp = temp.substr(0, i + j+1);
						continue;
					}					
					temp += s.substr(i+j+k);
					result.push_back(temp);
				}
				temp = temp.substr(0,i+j+1);
			}
			temp = temp.substr(0, i);
		}
		temp = "";
	}
	return result;
}

/*递归判断
*/
void recurIpAdress(string s, int nth, vector<string> &result, string temp){
	if (nth == 5){
		result.push_back(temp.substr(0, temp.length() - 1));
		return;
	}
	int min = s.length() - (4 - nth) * 3, max = s.length() - (4 - nth);
	min=min > 0 ? min : 1;
	max=max < 3 ? max : 3;
	for (int i = min; i <= max; i++){
		if (i == 3 && (s[0] == '1' || s[0] == '2' && (s[1] < '5' || s[1] == '5' && s[2] <= '5'))){
			recurIpAdress(s.substr(i), nth + 1, result, temp + s.substr(0, i) + '.');
		}
		else if (i == 2 && s[0] != '0' || i == 1){
			recurIpAdress(s.substr(i), nth + 1, result, temp + s.substr(0, i) + '.');
		}
	}

}
vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	string temp;
	recurIpAdress(s,1,result,temp);
	return result;
}