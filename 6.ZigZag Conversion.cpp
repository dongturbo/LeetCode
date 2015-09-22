string convert(string s, int numRows) {
       const char *str = s.c_str();
	int length = s.size();
	if (length == 0){
		return "";
	}
	if (numRows == 1){
		return s;
	}
	vector<char> result;
	int item = 2 * (numRows - 1);
	int ys = length%item;
	int last = (ys - 1 + item) % item;
	int sz = ys==0?length / item:length/item+1;
	for (int i = 0; i < numRows; i++){
		if (i == 0 || i == numRows-1){
			for (int j = 0; j < sz; j++){
				if (j == sz - 1 && i>last){
					break;
				}
				result.push_back(str[i+item*j]);
			}
		}
		else{
			for (int j = 0; j < sz; j++){
				if (!(j == sz - 1 && i>last)){
					result.push_back(str[i + item*j]);
				}
				if (!(j == sz - 1 && item - i > last)){
					result.push_back(str[item*j+item-i]);
				}
			}
		}
	}
    	

	return  string(result.begin(),result.end()); 
    }