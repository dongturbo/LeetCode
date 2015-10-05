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

//由于为了提高匹配的效率，因此本题利用的是KMP算法，不懂的Google一下

//求next[]函数
vector<int> getNext(string t){
	const char *str = t.c_str();
	
	int length = t.size(),i=1,j=0;
	vector<int> next(length);
	if (t == "")
		return next;
	next[0] = 0;
	while (i < length){
		if (j == 0 || str[i-1] == str[j-1]){
			++i;
			++j;
			if (str[i - 1 ]!= str[j - 1])
				next[i - 1] = j;
			else
				next[i - 1] = next[j - 1];
		}
		else{
			j = next[j-1];
		}
	}
	return next;
}

//匹配算法
int strStr(string haystack, string needle) {
	vector<int> next = getNext(needle);
	const char * str1 = haystack.c_str(), *str2 = needle.c_str();
	int length1 = haystack.size(), length2 = needle.size();
	int i = 1, j = 1;
	while (i <= length1&&j <=length2){
		if (j == 0 || str1[i-1] == str2[j-1]){
			++i;
			++j;
		}
		else{
			j = next[j-1];
		}
	}
	if (j > length2)
		return i - length2-1;
	else
		return -1;
}


int main(int argc, char *argv[]){
	
	int index = strStr("", "");
	cout << index << endl;
	return 0;
}
