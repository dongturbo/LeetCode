/*解题思路：
	1.根据'/'分割字符串，把不等于".",".."的添加到result中。
	2.每步都判断如果等于"."的话继续循环，如果等于".."的话result弹出一项。
	3.直到判断循环完整个字符串，然后把result转换成字符串返回。
*/
string simplifyPath(string path) {
	int length = path.size();
	vector<string> result;
	for (int i = 0; i < length; i++){
		string temp;
		while (i<length&&path[i] == '/')
			i++;
		while (i<length&&path[i] != '/'){
			temp += path[i];
			i++;
		}
		if (temp == "."){
			continue;
		}
		else if (temp == ".."){
			if (result.size() > 0){
				result.pop_back();
			}
		}
		else if(temp!=""){
			result.push_back(temp);
		}
	}
	string spath="";
	for (int i = 0; i < result.size(); i++){
		spath += '/'+result[i];
	}
	if (result.size() == 0)
		spath = "/";
	return spath;
}