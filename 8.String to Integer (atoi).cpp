int myAtoi(string str) {
        	int length = str.size();
	const char * s = str.c_str();
	long int_max = 2147483647;
	double result = 0;
	bool isDigit = false, isEnd = false, isNegative = false;
	for (int i = 0; i < length; i++){
		if (isEnd){
			break;
		}
		if (s[i] == ' ' && isDigit == false){
			continue;
		}
		else if ((s[i]=='-' || s[i]=='+') && !isDigit){
			if (s[i] == '-') isNegative = true;
			isDigit = true;
		}
		else if (s[i] >= '0' && s[i] <= '9'){
			result = result * 10 + s[i] - 48;
			isDigit = true;
		}
		else if (s[i]<'0' || s[i]>'9'){
			isEnd = true;
		}
	}
	result = isNegative ? -result : result;

	if (result > int_max){
		return int_max;
	}else if(result < -(int_max + 1)){
		return -(int_max + 1);
	}
	return (int)result;
    }