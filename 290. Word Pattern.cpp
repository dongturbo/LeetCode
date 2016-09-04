//首先按空格切分str字符串并存到vector中
bool wordPattern(string pattern, string str) {
	string t = "";
	vector<string> words;
	//切分字符串
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' ' ){
			words.push_back(t);
			t = "";
			continue;
		}
		t += str[i];
	}
	words.push_back(t);
	if (pattern.length() != words.size()){
		return false;
	}
	//保存两个的映射关系，这里保存的是前一个的下标
	unordered_map<string, int> wordMap;
	int patMap[128] = { 0 };
	//匹配下标，由于初试为0，所以让下标加1，去除默认为0，和第一组匹配无法区分的问题。
	for (int i = 0; i < words.size(); i++){
		if (wordMap[words[i]] != patMap[pattern[i]])
			return false;
		patMap[pattern[i]] = i+1;
		wordMap[words[i]] = i+1;
	}
	return true;
}
