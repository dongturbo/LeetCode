/*解题思路：
	首先获取到每个单词，然后把单词进行排序，然后放到map中，这样map中的value即为group
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string, vector<string>> matchMap;
	vector<vector<string>> result;
	int length = strs.size();
	sort(strs.begin(), strs.end());
	for (int i = 0; i < length; i++){
		string temp = strs[i];
		int len = strs[i].size();
		sort(temp.begin(),temp.end());
		matchMap[temp].push_back(strs[i]);
	}
	map<string, vector<string>>::iterator it;
	for (it = matchMap.begin(); it != matchMap.end(); it++)
		result.push_back(it->second);
	return result;
}
