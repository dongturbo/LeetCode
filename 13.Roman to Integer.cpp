int romanToInt(string s) {
	string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	int result = 0;

	for (int i = 0; i < sizeof(value) / sizeof(value[0]); i++){
		while (s.size() > 0){
			if (s.substr(0, 1) == symbol[i]){
				result += value[i];
				s = s.substr(1);
			}
			else if (s.substr(0, 2) == symbol[i]){
				result += value[i];
				s = s.substr(2);
			}
			else{
				break;
			}
		}
	}


	return result;
}