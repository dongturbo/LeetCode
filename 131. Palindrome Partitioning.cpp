void dfs(vector<vector<string>> & result,string &s,vector<string> &tempRes,int begin){
    if (begin >= s.length()){
    	result.push_back(tempRes);
    	return;
    }		
    for (int i = begin; i < s.length(); i++){
    	bool isPalin = true;
    	for (int j = 0; j < i-begin+1; j++){
    		if (s[begin + j] != s[i - j]){
    			isPalin = false;
    			break;
    		}
    	}
    	if (isPalin){
    		tempRes.push_back(s.substr(begin,i-begin+1));
    		dfs(result,s,tempRes,i+1);
    		tempRes.pop_back();
    	}
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> tempRes;
    dfs(result, s, tempRes, 0);
    return result;
}
