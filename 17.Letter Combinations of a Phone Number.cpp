//仔细分析题目会发现，用深度优先遍历适合解决这道题
void dfs(int depth, map<char, vector<char> > dict,string digits, string temp,vector<string> &result){
	const char * dig = digits.c_str();
	for (int i = 0; i < dict[dig[depth]].size(); i++){
		string temp1 =temp+ dict[dig[depth]][i];
		if (depth + 1 == digits.size()){
			result.push_back(temp1);
		}
		else{
			dfs(depth + 1, dict, digits, temp1, result);
		}
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> result;
	map<char, vector<char> > dict;
	dict['2'] = { 'a', 'b', 'c' };
	dict['3'] = { 'd', 'e', 'f' };
	dict['4'] = { 'g', 'h', 'i' };
	dict['5'] = { 'j', 'k', 'l' };
	dict['6'] = { 'm', 'n', 'o' };
	dict['7'] = { 'p', 'q', 'r','s' };
	dict['8'] = { 't', 'u', 'v' };
	dict['9'] = { 'w', 'x', 'y','z' };
	dfs(0,dict,digits,"",result);
	return result;
}