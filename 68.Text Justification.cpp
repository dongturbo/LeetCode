/*本题比较麻烦的地方就是计算单词之间到底该有多少个空格，思路是：
	1.遍历words数组，累加单词的长度。
	2.当单词的长度大于maxWidth时，去掉一个单词，然后均匀分布空格数，并置长度为0。
	3.遍历完后，由于最后的单词不一定大于maxWidth，所以得判断一下是否有漏下的元素。
*/
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> result;
	int length = 0, count = 0,wlength=words.size();
	for (int i = 0; i < wlength; length += words[i].size(), i++, count++){
		//当长度大于maxWidth，均匀分布单词之间的间隙
		if (length + words[i].size()+count>maxWidth){
			string temp="";
			int interval = maxWidth - length, eachInterval,mod;
			eachInterval =count>1? interval / (count - 1):interval;
			mod = count>1? interval % (count - 1):0;
			for (int j = 0; j < count; j++){
				temp += words[i-count+j];
				if (temp.size() == maxWidth)
					break;
				if (j < mod){
					temp += string(eachInterval + 1,' ');
				}
				else{
					temp += string(eachInterval, ' ');
				}
			}
			result.push_back(temp);
			length = 0;
			count = 0;
		}
	}
	//当最后还有剩余的单词时，补上
	if (count != 0){
		string temp = "";
		for (int i = 0; i < count; i++){
			temp += words[wlength - count + i];
			if (i != count - 1)
				temp += " ";
			else
				temp += string(maxWidth-temp.size(),' ');
		}
		result.push_back(temp);
	}
	return result;
}