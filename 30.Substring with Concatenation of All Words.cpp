#include "stdafx.h"
#include<string>
#include <cstdlib>
#include<iostream>
#include<vector>
#include<math.h>
#include<hash_map>
#include<stack>
#include<map>
#include <algorithm>
using namespace::std;

/*题目的要求是找出所有words中单词组成的字符串在s中出现的位置。
需要考虑的有：
	1.words中的单词有可能相同。
	2.无论有几个相同，必须确保words中的单词出现的频率和组成的字符串出现的频率一致，这样的字符串才是要求匹配的字符串。
因此我们不光要匹配所有出现的单词，还要匹配单词出现的频率，所以选择用map来存储单词并保存频率。
大体思路为：
	1.wordCount统计words中单词出现的频率。
	2.由于每个单词的长度是一致的，所以最外层循环只需从i循环到word.length(单词的长度)就行。
	3.内层循环从i遍历到s的末尾，每次得到一个单词，并统计出现的频率。
	4.如果单词出现的频率和words的频率一致，则存储匹配的起始位置。

*/
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> result;
	map<string, int> wordCount;
	if (s.size() <= 0 || words.size() <= 0){
		return result;
	}
	//统计words中word的词频
	for (int i = 0; i < words.size(); i++){
		wordCount[words[i]]++;
	}
	int length = s.size(), llength=words.size(),wlength = words[0].size();
	for (int i = 0; i < wlength; i++){
		//存储实际单词出现的频率
		map<string, int> actualWord;
		int beginMatch = i, count = 0;
		for (int j = i; j <= length - wlength; j += wlength){
			string word = s.substr(j, wlength);
			//此单词不在words中的单词，把一切记录word的变量重置，从j+word.length的位置重新遍历。
			if (wordCount.find(word) == wordCount.end()){
				actualWord.clear();
				count = 0;
				beginMatch = j + wlength;
				continue;
			}
			//匹配单词的个数
			count++;
			actualWord[word]++;
			//实际单词出现的频率超出了words中的词频，从匹配的首位置开始遍历递减，知道实际单词的个数小于或等于words的频率时停止
			if (actualWord[word] > wordCount[word]){
				string temp; 
				do{
					temp = s.substr(beginMatch, wlength);
					count--;
					actualWord[temp]--;
					beginMatch += wlength;
				} while (temp != word);
			}
			//此时匹配的单词个数与words中单词个数一直，保存起始位置，重置所有变量，然后j从起始位置往后移一个单词的位置重新开始匹配
			if (count == llength){
				result.push_back(beginMatch);
				actualWord.clear();
				count = 0;
				j = beginMatch;
				beginMatch = beginMatch + wlength;
			}
		}	
	}
	return result;
}


int main(int argc, char *argv[]){
	vector<int> result;
	//string s = "barfoofoobarthefoobarman";
	string s = "aaa";
	vector<string> words = { "aa", "aa" };
	result = findSubstring(s, words);
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}
