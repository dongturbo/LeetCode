    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        	if (strs.size()==0)
	            return result;
        	int j = 0;
        	while (true){
        		char temp;
        		if (strs[0].size() >j){
        			temp = strs[0][j];
        		}
        		else{
        			return result;
        		}
        		for (int i = 1; i < strs.size(); i++){
        			if (temp != strs[i][j])
        				return result;
        		}
        		result += temp;
        		j++;
        	}
        	return result;
    }