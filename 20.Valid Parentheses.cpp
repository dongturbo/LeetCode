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


bool isValid(string s) {
	const char * str = s.c_str();
	stack<char> stk;
	for (int i = 0; i < s.size(); i++){
		if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
			stk.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}'){
			if (stk.empty()){
				return false;
			}
			char temp=stk.top();
			stk.pop();
			switch (str[i]){
			case ')':
				if (temp != '('){
					return false;
				}
				break;
			case ']':
				if (temp != '['){
					return false;
				}
				break;
			case '}':
				if (temp != '{'){
					return false;
				}
				break;
			}
		}
	}
	return stk.empty();
}




int main(int argc, char *argv[]){

	cout << isValid("{[fg(sdfg][h(gdf)g][]}") << endl;

	

	return 0;
}
